#include <stdint.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

// Buffers for double buffering
volatile uint16_t adc_buffer_1[BUFFER_SIZE];
volatile uint16_t adc_buffer_2[BUFFER_SIZE];

// Flags and pointers
volatile uint16_t *active_buffer = adc_buffer_1;  // Buffer being filled
volatile uint16_t *processing_buffer = adc_buffer_2;  // Buffer being processed
volatile bool buffer_ready = false;  // Indicates if a buffer is ready for processing

void ADC_IRQHandler(void) {
    static uint16_t index = 0;

    // Simulate ADC value reading
    uint16_t adc_value = ADC_Read();

    // Store ADC value in the active buffer
    active_buffer[index++] = adc_value;

    // Check if the buffer is full
    if (index >= BUFFER_SIZE) {
        index = 0;

        // Swap buffers
        uint16_t *temp = processing_buffer;
        processing_buffer = active_buffer;
        active_buffer = temp;

        // Signal that a buffer is ready for processing
        buffer_ready = true;
    }
}

void ProcessBuffer(void) {
    if (buffer_ready) {
        buffer_ready = false;

        // Process the data in the processing buffer
        for (int i = 0; i < BUFFER_SIZE; i++) {
            uint16_t value = processing_buffer[i];
            // Perform some operation on the value
        }
    }
}

#include <stdint.h>
#include <stdio.h>

#define TOTAL_SAMPLES 1024
#define BURST_SIZE    128

// Simulated data buffer
uint16_t adc_buffer[TOTAL_SAMPLES];

// Example processing function
void process_burst(uint16_t* data, size_t length, int burst_index) {
    printf("Processing burst %d: first value = %d\n", burst_index, data[0]);
    // Add filtering, accumulation, etc.
}

void process_all_samples_in_bursts(void) {
    for (int i = 0; i < TOTAL_SAMPLES; i += BURST_SIZE) {
        process_burst(&adc_buffer[i], BURST_SIZE, i / BURST_SIZE);
    }
}

// Optional Enhancement: DMA + Callback
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef* hadc) {
    static uint8_t burst_index = 0;
    process_burst(&adc_buffer[burst_index * BURST_SIZE], BURST_SIZE, burst_index);
    burst_index = (burst_index + 1) % (TOTAL_SAMPLES / BURST_SIZE);
}

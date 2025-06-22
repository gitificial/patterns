#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define BUFFER_SIZE 5

typedef struct {
    int buffer[BUFFER_SIZE];
    int head;   // points to the next write position
    int tail;   // points to the next read position
    int count;  // number of elements currently in buffer
} RingBuffer;

// Initialize the ring buffer
void ring_init(RingBuffer *rb) {
    rb->head = 0;
    rb->tail = 0;
    rb->count = 0;
}

// Check if the buffer is full
bool ring_is_full(RingBuffer *rb) {
    return rb->count == BUFFER_SIZE;
}

// Check if the buffer is empty
bool ring_is_empty(RingBuffer *rb) {
    return rb->count == 0;
}

// Add an element to the ring buffer
bool ring_enqueue(RingBuffer *rb, int data) {
    if (ring_is_full(rb)) {
        return false; // Buffer full, cannot enqueue
    }
    rb->buffer[rb->head] = data;
    rb->head = (rb->head + 1) % BUFFER_SIZE;
    rb->count++;
    return true;
}

// Remove an element from the ring buffer
bool ring_dequeue(RingBuffer *rb, int *data) {
    if (ring_is_empty(rb)) {
        return false; // Buffer empty, cannot dequeue
    }
    *data = rb->buffer[rb->tail];
    rb->tail = (rb->tail + 1) % BUFFER_SIZE;
    rb->count--;
    return true;
}

int main() {
    RingBuffer rb;
    ring_init(&rb);

    // Enqueue some data
    for (int i = 1; i <= 6; i++) {
        if (ring_enqueue(&rb, i)) {
            printf("Enqueued: %d\n", i);
        } else {
            printf("Buffer full! Failed to enqueue %d\n", i);
        }
    }

    // Dequeue all data
    int value;
    while (ring_dequeue(&rb, &value)) {
        printf("Dequeued: %d\n", value);
    }

    // Try to dequeue from empty buffer
    if (!ring_dequeue(&rb, &value)) {
        printf("Buffer empty! Nothing to dequeue\n");
    }

    return 0;
}

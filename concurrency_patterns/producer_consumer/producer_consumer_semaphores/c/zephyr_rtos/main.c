#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

// Define thread stack sizes and priorities
#define STACK_SIZE 512
#define PRIORITY 5

K_THREAD_DEFINE(producer_tid, STACK_SIZE, producer_thread, NULL, NULL, NULL,
                PRIORITY, 0, 0);

K_THREAD_DEFINE(consumer_tid, STACK_SIZE, consumer_thread, NULL, NULL, NULL,
                PRIORITY, 0, 0);

// Define a semaphore with initial count 0, max count 1
K_SEM_DEFINE(my_sem, 0, 1);

// Producer thread function
void producer_thread(void)
{
    while (1) {
        printk("Producer: doing work...\n");
        k_msleep(1000);  // simulate work
        printk("Producer: signaling consumer\n");
        k_sem_give(&my_sem);  // signal
    }
}

// Consumer thread function
void consumer_thread(void)
{
    while (1) {
        printk("Consumer: waiting for signal\n");
        k_sem_take(&my_sem, K_FOREVER);  // block indefinitely
        printk("Consumer: received signal\n");
    }
}



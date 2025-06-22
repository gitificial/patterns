#include <stdio.h>
#include <string.h>

#define MAX_BITS 8

// Simulated bus line (shared SDA line) - 0 or 1
int bus_line = 1;

// Function to simulate bus read (what masters see on SDA line)
int read_bus() {
    return bus_line;
}

// Function to simulate bus write (masters drive SDA line)
void write_bus(int bit) {
    // Wired-AND behavior: if any master writes 0, bus is 0
    if (bit == 0) {
        bus_line = 0;
    }
    // If bit == 1, bus remains whatever lowest driven bit is
}

int main() {
    // Two masters' data to send (8 bits)
    int master1_data[MAX_BITS] = {1,0,1,0,1,1,0,1}; // Example data
    int master2_data[MAX_BITS] = {1,0,1,0,1,0,1,1}; // Competing data

    int master1_active = 1;
    int master2_active = 1;

    printf("Starting multi-master arbitration simulation\n");

    for (int bit = 0; bit < MAX_BITS; bit++) {
        bus_line = 1; // Reset bus line to released (high)

        // Masters write their bit to the bus
        if (master1_active) write_bus(master1_data[bit]);
        if (master2_active) write_bus(master2_data[bit]);

        // Masters read bus line after arbitration
        int bus_state = read_bus();

        // Check arbitration loss
        if (master1_active && master1_data[bit] != bus_state) {
            printf("Master 1 lost arbitration at bit %d\n", bit);
            master1_active = 0;
        }
        if (master2_active && master2_data[bit] != bus_state) {
            printf("Master 2 lost arbitration at bit %d\n", bit);
            master2_active = 0;
        }

        // If one master remains active, arbitration done
        if (master1_active && !master2_active) {
            printf("Master 1 wins arbitration\n");
            break;
        }
        if (master2_active && !master1_active) {
            printf("Master 2 wins arbitration\n");
            break;
        }

        // If both lost (tie or error), stop simulation
        if (!master1_active && !master2_active) {
            printf("Both masters lost arbitration (bus error?)\n");
            break;
        }
    }

    if (master1_active && master2_active) {
        printf("Both masters still active after arbitration (tie?)\n");
    }

    return 0;
}

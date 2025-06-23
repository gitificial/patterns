#include <stdio.h>
#include <math.h>

// ---------- Strategy Interface ----------
typedef uint8_t (*DimmingStrategy)(float level); // level from 0.0 to 1.0

// ---------- Linear Strategy ----------
uint8_t linear_dimming(float level) {
    if (level < 0.0f) level = 0.0f;
    if (level > 1.0f) level = 1.0f;
    return (uint8_t)(level * 255);
}

// ---------- Logarithmic Strategy ----------
uint8_t logarithmic_dimming(float level) {
    if (level <= 0.0f) return 0;
    if (level >= 1.0f) return 255;
    float gamma = 2.2f;
    return (uint8_t)(powf(level, gamma) * 255);
}

// ---------- Context ----------
typedef struct {
    DimmingStrategy strategy;
} DimmingController;

void set_strategy(DimmingController *ctrl, DimmingStrategy strategy) {
    ctrl->strategy = strategy;
}

uint8_t compute_brightness(DimmingController *ctrl, float level) {
    return ctrl->strategy(level);
}

int main() {
    DimmingController dimmer;

    // Use linear strategy
    set_strategy(&dimmer, linear_dimming);
    printf("Linear:\n");
    for (float l = 0.0f; l <= 1.0f; l += 0.2f) {
        printf(" Level %.1f → Brightness %d\n", l, compute_brightness(&dimmer, l));
    }

    // Switch to logarithmic strategy
    set_strategy(&dimmer, logarithmic_dimming);
    printf("\nLogarithmic:\n");
    for (float l = 0.0f; l <= 1.0f; l += 0.2f) {
        printf(" Level %.1f → Brightness %d\n", l, compute_brightness(&dimmer, l));
    }

    return 0;
}


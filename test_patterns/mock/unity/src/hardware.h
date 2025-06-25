#ifndef HARDWARE_H
#define HARDWARE_H

void fan_set_state(int on);  // 1 = on, 0 = off
float read_temperature(void);

#endif

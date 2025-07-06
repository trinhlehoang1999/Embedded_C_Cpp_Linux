#ifndef Watering_Logic_H
#define Watering_Logic_H

#include "config.h"

void automatic_watering_control(SystemMode_Typedef mode, int soil_moisture, int min_threshold, int max_threshold, 
                               unsigned long last_watering_time, unsigned long current_time, 
                               unsigned long watering_interval, unsigned long max_watering_duration);

#endif // Watering_Logic_H
#ifndef config_H
#define config_H

#define MODIFY_Actuator 0 // 1: Actuator is enabled, 0: Actuator is disabled

#define MODIFY_Temperature 30   // Example temperature value in degrees Celsius

#define MODIFY_Moisture 30     // Example soil moisture value in percentage

#define MODIFY_SystemMode 1 // 1: Automatic mode, 0: Manual mode

#define MODIFY_Manual_Button 0 // Example value for any other configuration

#define Modify_Cycle_Sensor_time 5 // Example value for cycle sensor time in seconds

#define MODIFY_Automatic_Button 1 // Example value for any other configuration

typedef enum {
    MANUAL,
    AUTOMATIC
} SystemMode_Typedef;

typedef struct {
    int min_moisture_threshold;  // Minimum temperature threshold in degrees Celsius
    int max_moisture_threshold;  // Maximum temperature threshold in degrees Celsius
    int max_watering_time;        // Maximum watering time in seconds
    int Cycle_Sensor_time;            // Cycle time in seconds
    SystemMode_Typedef current_mode; // Current system mode (MANUAL or AUTOMATIC)
} SystemConfig_Typedef;

#endif


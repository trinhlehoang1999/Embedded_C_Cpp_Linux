#ifndef SENSORS_H
#define SENSORS_H

typedef struct  {
    int temperature; // Temperature in degrees Celsius
    int moisture;    // Soil moisture level in percentage
} Get_Sensors_Typedef;

typedef enum {
    SENSOR_OK,
    SENSOR_ERROR
} Status_Sensor_Typedef;

void get_sensors(void);

typedef enum {
    OK,
    NOT_OK,
    Waiting
} FuctionStatus_Typedef;

FuctionStatus_Typedef Check_sensor_in_cyclic(void);

#endif
// SENSORS_H
// This header file defines the structure and function for sensor data retrieval.   
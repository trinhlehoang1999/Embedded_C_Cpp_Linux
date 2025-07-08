#include <stdio.h> // Needed for printf
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/sensors.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"

SystemConfig_Typedef system_config;
extern Get_Sensors_Typedef sensor_data;

void get_sensors(void) {
    

    // Simulate reading sensor values
    // In a real application, replace these with actual sensor reading logic
    sensor_data.temperature = MODIFY_Temperature; // Example temperature in degrees Celsius
    sensor_data.moisture = MODIFY_Moisture;    // Example soil moisture level in percentage
    // Print the sensor data for debugging purposes
    printf("Sensor Data is reading:\n");
    printf("+ Temperature: %d°C\n", sensor_data.temperature);
    printf("+ Moisture: %d%%\n", sensor_data.moisture);
       
}

FuctionStatus_Typedef Check_sensor_in_cyclic()
{
    if (Modify_Cycle_Sensor_time == system_config.Cycle_Sensor_time) {
        // Simulate checking sensor status in a cyclic manner
        // In a real application, this would involve checking the actual sensor hardware
        printf("Checking sensors in cyclic mode...\n");
        get_sensors(); // Call the function to get sensor data
        return OK; // Return OK if sensors are functioning properly
    } else if (system_config.Cycle_Sensor_time < Modify_Cycle_Sensor_time){
        printf("Sensor check failed: Cycle time is not set.\n");
        return NOT_OK; // Return NOT_OK if there is an issue
    } else {
        printf("Waiting for the next cycle to check sensors...\n");
        return Waiting; // Return Waiting if the system is waiting for the next cycle
    }
}
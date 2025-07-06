#include <stdio.h>
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/buttons.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/sensors.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/watering_logic.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/actuators.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"

SystemConfig_Typedef system_config;

void Initialize_system_Parameter(void)
{
    // Initialize the system components, if needed
    printf("System components initialized.\n");
    system_config.max_moisture_threshold = 100; // Set the maximum moisture threshold
    system_config.min_moisture_threshold = 0; // Set the minimum moisture threshold
    system_config.max_watering_time = 120; // Set the maximum watering time in seconds
    system_config.Cycle_Sensor_time = 5; // Set the cycle time for sensor readings in minutes
    system_config.current_mode = handle_button_mode(); // the current mode based on button state
}

int main()
{
    int ret = 0;
    // Initialize the system, if needed
    printf("System initialized.\n");
    // Call the function to activate the pump
    Initialize_system_Parameter();
    printf("Hello, World12345!\n");
    get_sensors(); // Retrieve sensor data
    ret = get_pump_state(); // Get the current state of the pump
    if (ret == PUMP_ON) {
        printf("Pump is currently ON.\n");
    } else {
        printf("Pump is currently OFF.\n");
    }

    printf("Current system mode: %s\n", (system_config.current_mode == AUTOMATIC) ? "Automatic" : "Manual");

    ret = Check_sensor_in_cyclic(); // Check sensors in cyclic mode
    if (ret == OK) {
        printf("Sensors are functioning properly.\n");
    } else if (ret == NOT_OK) {
        printf("Sensors check failed.\n");
    } else {
        printf("Waiting for the next cycle to check sensors...\n");
    }
    return 0;
}
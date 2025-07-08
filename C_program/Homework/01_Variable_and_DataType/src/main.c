#include <stdio.h>
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/buttons.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/watering_logic.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/actuators.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"



void Initialize_system_Parameter(void)
{
    // Initialize the system components, if needed
    system_config.max_moisture_threshold = 80; // Set the maximum moisture threshold
    system_config.min_moisture_threshold = 20; // Set the minimum moisture threshold
    system_config.max_watering_time = 120; // Set the maximum watering time in seconds
    system_config.Cycle_Sensor_time = 5; // Set the cycle time for sensor readings in minutes
    system_config.current_mode = handle_button_mode(); // the current mode based on button state
    printf("System parameters initialized:\n");
    printf("+ Max Moisture Threshold: %d%%\n", system_config.max_moisture_threshold);
    printf("+ Min Moisture Threshold: %d%%\n", system_config.min_moisture_threshold);
    printf("+ Max Watering Time: %d seconds\n", system_config.max_watering_time);
    printf("+ Cycle Sensor Time: %d minutes\n", system_config.Cycle_Sensor_time);
    printf("+ Current Mode: %s\n", (system_config.current_mode == AUTOMATIC) ? "AUTOMATIC" : 
                                  (system_config.current_mode == MANUAL) ? "MANUAL" : "OFF");
    // Initialize other system parameters as needed
}

int main()
{
    SystemMode_Typedef ret;
    // Initialize the system, if needed
    Initialize_system_Parameter();
    // do {
        ret = handle_button_mode(); // Handle button presses to switch between manual and automatic modes
        if (ret == AUTOMATIC) {
            printf("System is in AUTOMATIC mode.\n");
            run_automic_watering(); // Run automatic watering logic
        } else if (ret == MANUAL) {
            printf("System is in MANUAL mode.\n");
            run_manual_watering(); // Run manual watering logic
        } else {
            printf("System is OFF.\n");
            deactivate_pump(); // Deactivate the pump if the system is OFF
        }  
    // } while (1); // Infinite loop to keep the program running
      
    return 0;
}
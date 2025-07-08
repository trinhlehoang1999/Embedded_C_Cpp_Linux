#include <stdio.h>
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/buttons.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/sensors.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/watering_logic.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/actuators.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"

Get_Sensors_Typedef sensor_data;

void timer_counter()
{

}

void run_automic_watering()
{
    // This function should implement the logic for automatic watering control.
    // For demonstration purposes, we will print a message indicating that the system is in automatic mode.    
    if (system_config.current_mode == AUTOMATIC) {
        printf("Automatic watering control is active.\n");
        if (sensor_data.moisture < system_config.min_moisture_threshold) {
            // If soil moisture is below the minimum threshold, activate the pump
            printf("Soil moisture is below the minimum threshold. Activating pump...\n");
            activate_pump();
        } else if (sensor_data.moisture > system_config.max_moisture_threshold) {
            // If soil moisture is above the maximum threshold, deactivate the pump
            printf("Soil moisture is above the maximum threshold. Deactivating pump...\n");
            deactivate_pump();
        } else {
            // If soil moisture is within the acceptable range, do nothing
            printf("Soil moisture is within the acceptable range. No action needed.\n");
        }


    } else {
        printf("System is in manual mode. Automatic watering control is not active.\n");
    }
}

void run_manual_watering()
{
    // This function should implement the logic for manual watering control.
    // For demonstration purposes, we will print a message indicating that the system is in manual mode.
    if (system_config.current_mode == MANUAL) {
        printf("Manual watering control is active.\n");
        if (Read_button_Manual_mode()) {
            printf("Manual button pressed. Activating pump...\n");
            activate_pump();
        } else {
            printf("Manual button not pressed. Deactivating pump...\n");
            deactivate_pump();
        }
    } else {
        printf("System is in automatic mode. Manual watering control is not active.\n");
    }
}   

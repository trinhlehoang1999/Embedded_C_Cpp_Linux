
#include <stdio.h> // Needed for printf
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/actuators.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"

int sensor_value_Pump = 0; // Example sensor value, replace with actual sensor reading logic

void activate_pump(void) {
    printf("Pump activated.\n");
    output_led_state(LED_WATERING);
}

void deactivate_pump(void) {
    printf("Pump deactivated.\n");
    output_led_state(LED_NORMAL);
}

void output_led_state(LedSate_Typedef led_state) {
    switch (led_state) {
        case LED_NORMAL:
            printf("LED is in normal state.\n");
            break;
        case LED_WATERING: 
            printf("LED is indicating watering state.\n");
            break;          
        case LED_LOW_MOISTURE:
            printf("LED is indicating low moisture state.\n");
            break;
        case LED_ERROR:
            printf("LED is indicating error state.\n");
            break;
        default:
            printf("Unknown LED state.\n");
            break;
    }
}                           
PumpState_Typedef get_pump_state(void) {
    // This function should return the current state of the pump.
    // For demonstration purposes, we will return PUMP_ON.
    if (MODIFY_Actuator) {
        output_led_state(LED_WATERING);
        return PUMP_ON;
    } else {
        output_led_state(LED_NORMAL);
        return PUMP_OFF;
    }
}   
#include <stdio.h> // Needed for printf
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/buttons.h"
#include <stdbool.h>


SystemMode_Typedef handle_button_mode(void) {
    // This function should handle button presses to switch between manual and automatic modes.
    // For demonstration purposes, we will return AUTOMATIC mode.
    
    if (Read_button_Manual_mode() && Read_button_Automatic_mode()) {
        return AUTOMATIC;
    } else if(!Read_button_Manual_mode() && Read_button_Automatic_mode()) {
        return AUTOMATIC;
    } else if (Read_button_Manual_mode() && !Read_button_Automatic_mode()) {
        return MANUAL;
    } else {
        // If neither button is pressed, we can assume the system remains in its current mode.
        return OFF;
    }
}

bool Read_button_Manual_mode(void) {
    // This function simulates reading the state of the manual mode button.
    // In a real application, replace this with actual button reading logic.
    
    if (MODIFY_Manual_Button) {
        return true; // Button is pressed
    } else {
        return false; // Button is not pressed
    }
}

bool Read_button_Automatic_mode(void) {
    // This function simulates reading the state of the automatic mode button.
    // In a real application, replace this with actual button reading logic.
    
    if (MODIFY_Automatic_Button) {
//        printf("Automatic button pressed.\n");
        return true; // Button is pressed
    } else {
        printf("Automatic button not pressed.\n");
//        return false; // Button is not pressed
    }
}
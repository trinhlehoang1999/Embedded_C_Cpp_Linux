#ifndef BUTTONS_H
#define BUTTONS_H   

#include <stdio.h> // Needed for printf
#include "config.h"
#include <stdbool.h>

bool Read_button_Manual_mode(void); // Function to read the button state for Manual mode
bool Read_button_Automatic_mode(void); // Function to read the button state for Automatic mode

SystemMode_Typedef handle_button_mode(void);

#endif
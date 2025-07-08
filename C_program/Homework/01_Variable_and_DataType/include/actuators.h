#ifndef ACTUATORS_H
#define ACTUATORS_H

typedef enum {
    PUMP_OFF,
    PUMP_ON
} PumpState_Typedef;

typedef enum {
    LED_NORMAL,
    LED_WATERING,  
    LED_LOW_MOISTURE,
    LED_ERROR   
} LedSate_Typedef;

PumpState_Typedef get_pump_state(void);

void activate_pump(void);
void deactivate_pump(void);
void output_led_state(LedSate_Typedef led_state);

#endif // ACTUATORS_H
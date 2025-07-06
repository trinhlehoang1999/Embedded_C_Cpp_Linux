#ifndef ACTUATORS_H
#define ACTUATORS_H

void activate_pump(void);
void deactivate_pump(void);



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

#endif // ACTUATORS_H
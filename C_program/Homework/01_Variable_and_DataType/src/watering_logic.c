#include <stdio.h>
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/buttons.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/sensors.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/watering_logic.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/actuators.h"
#include "/home/hoang/Workspace/01_learning/C_program/Homework/01_Variable_and_DataType/include/config.h"


void automatic_watering_control(SystemMode_Typedef mode, int soil_moisture, int min_threshold, int max_threshold, 
                               unsigned long last_watering_time, unsigned long current_time, 
                               unsigned long watering_interval, unsigned long max_watering_duration) {
    static int pump_on = 0;
    static unsigned long pump_start_time = 0;

    if (mode == AUTOMATIC) {
        if (!pump_on) {
            // Kiểm tra điều kiện kích hoạt bơm
            if (soil_moisture < min_threshold && (current_time - last_watering_time) > watering_interval) {
                activate_pump();
                pump_on = 1;
                pump_start_time = current_time;
            }
        } else {
            // Đang tưới, kiểm tra điều kiện dừng bơm
            if (soil_moisture >= max_threshold || (current_time - pump_start_time) > max_watering_duration) {
                deactivate_pump();
                pump_on = 0;
            }
        }
    } else {
        // Nếu không ở chế độ tự động, đảm bảo bơm tắt
        if (pump_on) {
            deactivate_pump();
            pump_on = 0;
        }
    }
}
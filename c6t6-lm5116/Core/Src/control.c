//
// Created by 86136 on 2022/10/15.
//

#include "control.h"
#include "key.h"

extern uint8_t data;

void Adjust_Voltage() {
    if (Enter_Key() == RESISTANCE_DOWN) {
        data--;
    } else if (Enter_Key() == RESISTANCE_UP) {
        data++;
    } else if (Enter_Key() == ENTER) {

    } else if (Enter_Key() == SELECT) {

    }
}
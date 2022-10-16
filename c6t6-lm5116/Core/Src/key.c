//
// Created by 86136 on 2022/10/15.
//

#include "key.h"

uint8_t Enter_Key() {
    uint8_t flag = 0;
    if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_RESET) {
        HAL_Delay(10);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_12) == GPIO_PIN_RESET);
        HAL_Delay(10);
        flag = RESISTANCE_UP;
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == GPIO_PIN_RESET) {
        HAL_Delay(10);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_13) == GPIO_PIN_RESET);
        HAL_Delay(10);
        flag = RESISTANCE_DOWN;
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_RESET) {
        HAL_Delay(10);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_14) == GPIO_PIN_RESET);
        HAL_Delay(10);
        flag = ENTER;
    } else if (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15) == GPIO_PIN_RESET) {
        HAL_Delay(10);
        while (HAL_GPIO_ReadPin(GPIOB, GPIO_PIN_15) == GPIO_PIN_RESET);
        HAL_Delay(10);
        flag = SELECT;
    }
    return flag;
}
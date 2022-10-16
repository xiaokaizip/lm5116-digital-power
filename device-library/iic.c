//
// Created by LaoZhu on 2022/3/3.
//

#include "iic.h"
#include "stm32f1xx_hal.h"
#include "delay.h"

#define IIC_SDA     GPIO_PIN_9
#define IIC_CLK     GPIO_PIN_8

void IIC_Start(void) {
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_SET);
    delayus(2);
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_RESET);
    delayus(2);
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
    delayus(2);
}

void IIC_Stop(void) {
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_RESET);
    delayus(2);
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_SET);
    delayus(2);
}

unsigned char IIC_Wait_Ask(void) {
    int count = 0;
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_SET);
    delayus(2);
    while (HAL_GPIO_ReadPin(GPIOB, IIC_SDA)) {
        count++;
        if (count > 250) {
            IIC_Stop();
            return 1;
        }
    }
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
    delayus(2);
    return 0;
}

void IIC_WriteByte(unsigned char data) {
    unsigned char i;
    for (i = 0; i < 8; i++) {
        HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
        delayus(2);
        if (data & 0x80)
            HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_SET);
        else
            HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_RESET);
        HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_SET);
        delayus(2);
        HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
        data <<= 1;
    }
}

unsigned char IIC_ReadByte(void) {
    unsigned char data, i;
    HAL_GPIO_WritePin(GPIOB, IIC_SDA, GPIO_PIN_SET);
    delayus(2);
    for (i = 0; i < 8; i++) {
        data <<= 1;
        HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
        delayus(2);
        HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_SET);
        delayus(2);
        if (HAL_GPIO_ReadPin(GPIOB, IIC_SDA))
            data = data | 0x01;
        else
            data = data & 0xFE;
    }
    HAL_GPIO_WritePin(GPIOB, IIC_CLK, GPIO_PIN_RESET);
    delayus(2);
    return data;
}

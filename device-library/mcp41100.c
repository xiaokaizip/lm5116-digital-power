//
// Created by 86136 on 2022/10/9.
//
#include "gpio.h"
#include "spi.h"

uint8_t command;
uint8_t data;

void MCP41100_Send_Data(uint8_t commands, uint8_t datas) {
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);//来低数字电位器的CS引脚，开始准备通讯
    HAL_Delay(0);
    HAL_SPI_Transmit(&hspi1, &command, 1, 0xffff);//传送命令字节
    HAL_SPI_Transmit(&hspi1, &data, 1, 0xffff);//传送数据字节
    HAL_Delay(0);
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_4, GPIO_PIN_SET);//将CS引脚拉高，关闭通讯
}

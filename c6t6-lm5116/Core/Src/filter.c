//
// Created by 86136 on 2022/10/15.
//

#include "filter.h"
#include "adc.h"

volatile unsigned short adc_value[40];

float DMA_Start() {
    float sum = 0;
    float average = 0;

    HAL_ADC_Start_DMA(&hadc1, (uint32_t *) adc_value, 40);

    for (int i = 0; i < 40; i++) {
        sum += (float) adc_value[i] * 0.004833f;
    }

    average = sum / 40.0f;
    HAL_ADC_Stop_DMA(&hadc1);
    return average;
}

uint8_t flag = 0;
float avgerage_voltage = 0;
float last_voltage = 0;

void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc) {
    uint32_t sum = 0;
    for (uint8_t i = 0; i < 40; i++) {
        sum += adc_value[i];
    }
    avgerage_voltage = (float) sum / 40.0f;
    avgerage_voltage = avgerage_voltage * 0.2f + last_voltage * 0.8f;
    last_voltage = avgerage_voltage;
    flag = 1;

}
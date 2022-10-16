#include "usart.h"
#include <math.h>

/**
 * ��8λ���޷�������ת��Ϊ����
 * @param buff
 * @return
 */
int uint8Toint(uint8_t buff) {
    int num = 0;
    for (int i = 0; i < 8; i++) {
        if (buff & (1 << i)) {
            num += pow(2, i);
        }
    }
    return num;
}

/**
 * ��16λ���޷�������ת��Ϊ����
 * @param buff
 * @return
 */
int uint16Toint(uint16_t buff) {

    int num = 0;
    for (int i = 0; i < 16; i++) {
        if (buff & (1 << i)) {
            num += pow(2, i);
        }
    }
    return num;
}

/**
 * ��32λ���޷�������ת��Ϊ����
 * @param buff
 * @return
 */
int uint32Toint(uint32_t buff) {

    int num = 0;
    for (int i = 0; i < 32; i++) {
        if (buff & (1 << i)) {
            num += pow(2, i);
        }
    }
    return num;
}

/**
 * ��8λ���޷�������ת��Ϊ�ַ�������ͨ���������(0~255)
 * @param buff
 */
void uint8PrintIn(uint8_t num) {
    char ch[10];
    int i = 0;
    while (1) {
        if (num < 10) {
            break;
        }
        ch[i] = '0' + num % 10;
        i++;
        num /= 10;

    }
    ch[i] = '0' + num % 10;
    for (int j = 0; j < (i + 1) / 2; j++) {
        char temp = ch[j];
        ch[j] = ch[i - j];
        ch[i - j] = temp;

    }
    HAL_UART_Transmit(&huart1, ch, i + 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, "\r\n", 2, HAL_MAX_DELAY);

}

/**
 * ��16λ���޷�������ת��Ϊ�ַ�������ͨ���������(0~65535)
 * @param buff
 */
void uint16PrintIn(uint16_t num) {
    char ch[10];
    int i = 0;
    while (1) {
        if (num < 10) {
            break;
        }
        ch[i] = '0' + num % 10;
        i++;
        num /= 10;

    }
    ch[i] = '0' + num % 10;
    for (int j = 0; j < (i + 1) / 2; j++) {
        char temp = ch[j];
        ch[j] = ch[i - j];
        ch[i - j] = temp;

    }
    HAL_UART_Transmit(&huart1, ch, i + 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, "\r\n", 2, HAL_MAX_DELAY);
}

/**
 * ��32λ���޷�������ת��Ϊ�ַ�������ͨ���������(0~4,294,967,295)
 * @param buff
 */
void uint32PrintIn(uint32_t num) {
    char ch[10];
    int i = 0;

    while (1) {
        if (num < 10) {
            break;
        }
        ch[i] = '0' + num % 10;
        i++;
        num /= 10;

    }
    ch[i] = '0' + num % 10;
    for (int j = 0; j < (i + 1) / 2; j++) {
        char temp = ch[j];
        ch[j] = ch[i - j];
        ch[i - j] = temp;

    }
    HAL_UART_Transmit(&huart1, ch, i + 1, HAL_MAX_DELAY);
    HAL_UART_Transmit(&huart1, "\r\n", 2, HAL_MAX_DELAY);
}

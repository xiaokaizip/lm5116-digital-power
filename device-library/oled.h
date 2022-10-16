//
// Created by LaoZhu on 2022/3/3.
//

#ifndef PROGRAM_OLED_H
#define PROGRAM_OLED_H

void OLED_Fill(unsigned char fill_Data);

void OLED_ShowStr(unsigned char x, unsigned char y, const char *ch);

void OLED_Init(void);

#endif //PROGRAM_OLED_H

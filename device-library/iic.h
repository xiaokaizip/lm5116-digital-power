//
// Created by LaoZhu on 2022/3/3.
//

#ifndef PROGRAM_IIC_H
#define PROGRAM_IIC_H

void IIC_Start(void);

void IIC_Stop(void);

unsigned char IIC_Wait_Ask(void);

void IIC_WriteByte(unsigned char data);

unsigned char IIC_ReadByte(void);

#endif //PROGRAM_IIC_H

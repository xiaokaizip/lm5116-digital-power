//
// Created by 86136 on 2022/10/9.
//

#ifndef C6T6_LM5116_MCP41100_H
#define C6T6_LM5116_MCP41100_H


#define MCP41100_ENABLE     0B00010011
#define MCP41100_DISABLE    0B00100000


void MCP41100_Send_Data(uint8_t command, uint8_t data);

#endif //C6T6_LM5116_MCP41100_H

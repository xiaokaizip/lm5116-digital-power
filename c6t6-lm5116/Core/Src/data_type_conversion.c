//
// Created by 86136 on 2022/10/10.
//
/**
 * 将得到的数字转化为字符串形式，使其可以在屏幕上显示
 * @param num
 * @param str
 * @param len
 */
void numTostring(float num, char str[10]) {

    char ch[10];
    int i = 0;//跟随ch
    int j = 0;//跟随str
    //判断是否是负数
    if (num < 0) {
        num = -num;
        str[j++] = '-';

    }
    //判断是否是小数，如果是小数，先加上0；
    if (num < 1) {
        str[j++] = '0';

    }
    //将小数乘上1000，意味着将该数字精确到小数点后三位，要改精度就改一下1000这个数字就行
    num *= 1000;
    int nums = (int) num;//将小数转换为整数
    for (i = 8; i >= 0; i--) {
        if (i == 5) {
            ch[i] = '.';
            i--;
        }
        ch[i] = nums % 10 + '0';
        nums /= 10;
    }
    //加上小数点
    ch[9] = '\0';
    i = 0;
    while (ch[i] == '0') {
        i++;
    }
    for (i; i <= 9; i++) {
        str[j] = ch[i];
        j++;
    }
}

//
// Created by 86136 on 2022/10/10.
//
/**
 * ���õ�������ת��Ϊ�ַ�����ʽ��ʹ���������Ļ����ʾ
 * @param num
 * @param str
 * @param len
 */
void numTostring(float num, char str[10]) {

    char ch[10];
    int i = 0;//����ch
    int j = 0;//����str
    //�ж��Ƿ��Ǹ���
    if (num < 0) {
        num = -num;
        str[j++] = '-';

    }
    //�ж��Ƿ���С���������С�����ȼ���0��
    if (num < 1) {
        str[j++] = '0';

    }
    //��С������1000����ζ�Ž������־�ȷ��С�������λ��Ҫ�ľ��Ⱦ͸�һ��1000������־���
    num *= 1000;
    int nums = (int) num;//��С��ת��Ϊ����
    for (i = 8; i >= 0; i--) {
        if (i == 5) {
            ch[i] = '.';
            i--;
        }
        ch[i] = nums % 10 + '0';
        nums /= 10;
    }
    //����С����
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

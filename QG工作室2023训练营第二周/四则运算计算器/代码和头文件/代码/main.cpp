#define _CRT_SECURE_NO_WARNINGS

#include "..\Head\operate.h"




int main()
{
    // ��������Ľ���ַ���
    char buffer[256] = { 1 };

    char str[1024] = { 0 };//������ÿ��Ԫ�ظ�ֵΪ'\0'
    printf("����������������ʽ:\n");
    scanf("%s", str);
    int number = transform(str, buffer);
    
    if (number == -1)
    {
        printf("���ʽת������:\n");
    }
    else if (number == 1)
    {
        printf("ת����ı��ʽ: %s\n", buffer);
    }
    else
    {
        return 0;
    }
}


#define _CRT_SECURE_NO_WARNINGS

#include "..\Head\operate.h"




int main()
{
    // 最终输出的结果字符串
    char buffer[256] = { 1 };

    char str[1024] = { 0 };//将数组每个元素赋值为'\0'
    printf("请输入四则运算表达式:\n");
    scanf("%s", str);
    int number = transform(str, buffer);
    
    if (number == -1)
    {
        printf("表达式转换错误:\n");
    }
    else if (number == 1)
    {
        printf("转化后的表达式: %s\n", buffer);
    }
    else
    {
        return 0;
    }
}


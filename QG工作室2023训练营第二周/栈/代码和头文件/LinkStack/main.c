#define _CRT_SECURE_NO_WARNINGS

#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include "../head/LinkStack.h" 

int main()
{
    LinkStack* s = (LinkStack*)malloc(sizeof(LinkStack));
    int i = 1;
    ElemType x;
    initLStack(s);
    while (i)//保证一直进行
    {
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   入栈    \n");
        printf("    2   出栈   \n");
        printf("    3   读取栈顶元素   \n");
        printf("    4   清空栈   \n");
        printf("    5   检测栈长度   \n"); 
        printf("    6   销毁栈   \n");
        printf("    7   判断栈是否为空   \n"); 
        printf("    8   初始化栈   \n");
        printf("    0   结束程序      \n");
        printf("------------------------------------\n");
        printf("请输入你选择的菜单号<1, 2, 3, 4, 5, 6, 7, 8, 0>:\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("请输入入栈元素：");
            scanf("%d", &x);
            if (!pushLStack(s, x))
            {
                printf("功能出错\n");
                break;
            }
            printf("\n\n");
            break;
        case 2:
            if (!popLStack(s, &x))
            {
                printf("功能出错\n");
                break;
            }
            printf("出栈元素为: %d", x);
            printf("\n\n");
            break;
        case 3:
            if (!getTopLStack(s, &x))
            {
                printf("功能出错\n");
                break;
            }
            printf("栈顶元素为：%d",x);
            printf("\n\n");
            break;
        case 4:
            if (!clearLStack(s))
            {
                printf("功能出错\n");
                break;
            }
            printf("\n\n");
            break;
        case 5:
            if (!LStackLength(s, &x))
            {
                printf("功能出错\n");
                break;
            }
            printf("栈长度为: %d", x);
            printf("\n\n");
            break;
        case 6:
            if (!destroyLStack(s))
            {
                printf("功能出错\n");
                break;
            }
            printf("\n\n");
            break;
        case 7:
            if (isEmptyLStack(s))
            {
                printf("栈为空");
            }
            else {
                printf("栈不为空");
            }
            printf("\n\n");
            break;
        case 8:
            if (!initLStack(s))
            {
                printf("功能出错\n");
                break;
            }
            printf("\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("输入有误~\n");
            break;
        }
    }
    return 0;
}















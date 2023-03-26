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
    while (i)//��֤һֱ����
    {
        printf("------------------------------------\n");
        printf("         Main Menu         \n");
        printf("    1   ��ջ    \n");
        printf("    2   ��ջ   \n");
        printf("    3   ��ȡջ��Ԫ��   \n");
        printf("    4   ���ջ   \n");
        printf("    5   ���ջ����   \n"); 
        printf("    6   ����ջ   \n");
        printf("    7   �ж�ջ�Ƿ�Ϊ��   \n"); 
        printf("    8   ��ʼ��ջ   \n");
        printf("    0   ��������      \n");
        printf("------------------------------------\n");
        printf("��������ѡ��Ĳ˵���<1, 2, 3, 4, 5, 6, 7, 8, 0>:\n");
        scanf("%d", &i);
        switch (i)
        {
        case 1:
            printf("��������ջԪ�أ�");
            scanf("%d", &x);
            if (!pushLStack(s, x))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("\n\n");
            break;
        case 2:
            if (!popLStack(s, &x))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("��ջԪ��Ϊ: %d", x);
            printf("\n\n");
            break;
        case 3:
            if (!getTopLStack(s, &x))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("ջ��Ԫ��Ϊ��%d",x);
            printf("\n\n");
            break;
        case 4:
            if (!clearLStack(s))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("\n\n");
            break;
        case 5:
            if (!LStackLength(s, &x))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("ջ����Ϊ: %d", x);
            printf("\n\n");
            break;
        case 6:
            if (!destroyLStack(s))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("\n\n");
            break;
        case 7:
            if (isEmptyLStack(s))
            {
                printf("ջΪ��");
            }
            else {
                printf("ջ��Ϊ��");
            }
            printf("\n\n");
            break;
        case 8:
            if (!initLStack(s))
            {
                printf("���ܳ���\n");
                break;
            }
            printf("\n\n");
            break;
        case 0:
            return 0;
        default:
            printf("��������~\n");
            break;
        }
    }
    return 0;
}















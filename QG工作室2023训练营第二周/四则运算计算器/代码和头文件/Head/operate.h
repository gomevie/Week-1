#define _CRT_SECURE_NO_WARNINGS

#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>



typedef  struct StackNode
{
	char data;
	struct StackNode* next;
}StackNode, * LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;

//��ջ
int initLStack(LinkStack* s);//��ʼ��ջ    
int isEmptyLStack(LinkStack* s);//�ж�ջ�Ƿ�Ϊ��
int pushLStack(LinkStack* s, char data);//��ջ
int popLStack(LinkStack* s, char* data);//��ջ
int getTopLStack(LinkStack* s, char* e);//�õ�ջ��Ԫ��


//����
void char_put(char ch,char buffer[]);//�������ַ���������
int priority(char ch);//���ظ��ַ������ȼ�
int is_number(char ch);//�жϱ��������ַ��ǲ�������
int is_operator(char ch);//�жϱ��������ַ��ǲ��������
int is_left(char ch);//�ж��ַ��ǲ���������
int is_right(char ch);//�ж��ַ��ǲ���������


//����
int transform(char str[],char buffer[]);

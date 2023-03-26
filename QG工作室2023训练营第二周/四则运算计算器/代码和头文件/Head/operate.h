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

//链栈
int initLStack(LinkStack* s);//初始化栈    
int isEmptyLStack(LinkStack* s);//判断栈是否为空
int pushLStack(LinkStack* s, char data);//入栈
int popLStack(LinkStack* s, char* data);//出栈
int getTopLStack(LinkStack* s, char* e);//得到栈顶元素


//运算
void char_put(char ch,char buffer[]);//用来将字符放入结果串
int priority(char ch);//返回该字符的优先级
int is_number(char ch);//判断遍历到的字符是不是数字
int is_operator(char ch);//判断遍历到的字符是不是运算符
int is_left(char ch);//判断字符是不是左括号
int is_right(char ch);//判断字符是不是右括号


//运行
int transform(char str[],char buffer[]);

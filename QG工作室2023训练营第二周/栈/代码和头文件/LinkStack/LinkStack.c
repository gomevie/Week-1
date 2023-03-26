#define _CRT_SECURE_NO_WARNINGS

#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include "../head/LinkStack.h" 
//链栈

//初始化栈
Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0;
	return 1;
}

//判断栈是否为空
Status isEmptyLStack(LinkStack *s){
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//得到栈顶元素
Status getTopLStack(LinkStack *s,ElemType *e){
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		printf("栈内无元素\n");
		return 0;
	}
	else
	{
		*e = p->data;
		return 1;
	}
}

//清空栈
Status clearLStack(LinkStack *s){
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	while (p != NULL)
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	s->top = NULL;
	s->count = 0;
	return 1;
}

//销毁栈
Status destroyLStack(LinkStack *s){
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	while (p != NULL)
	{
		s->top = p->next;
		free(p);
		p = s->top;
	}
	free(s);
	return 1;
}

//检测栈长度
Status LStackLength(LinkStack *s,int *length){
	if (s == NULL)
		return 0;
	*(length) = s->count;
	return 1;
}

//入栈
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
		return 0;
	p->data = data;//头插法
	p->next = s->top;
	s->top = p;
	s->count++;
	return 1;
}

//出栈
Status popLStack(LinkStack *s,ElemType *data){
	if (s == NULL)
		return 0;
	StackNode* p = s->top; 
	if (p == NULL)
	{
		printf("栈内无元素\n");
		return 0;
	}
	else
	{
		s->top = p->next;//往后挪一位
		*data = p->data;
		free(p);
		s->count--;
		return 1;
	}
}




#define _CRT_SECURE_NO_WARNINGS

#include<malloc.h>
#include<stdlib.h>
#include<stdio.h>
#include "../head/LinkStack.h" 
//��ջ

//��ʼ��ջ
Status initLStack(LinkStack *s){
	s->top = NULL;
	s->count = 0;
	return 1;
}

//�ж�ջ�Ƿ�Ϊ��
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

//�õ�ջ��Ԫ��
Status getTopLStack(LinkStack *s,ElemType *e){
	if (s == NULL)
		return 0;
	StackNode* p = s->top;
	if (p == NULL)
	{
		printf("ջ����Ԫ��\n");
		return 0;
	}
	else
	{
		*e = p->data;
		return 1;
	}
}

//���ջ
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

//����ջ
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

//���ջ����
Status LStackLength(LinkStack *s,int *length){
	if (s == NULL)
		return 0;
	*(length) = s->count;
	return 1;
}

//��ջ
Status pushLStack(LinkStack *s,ElemType data){
	StackNode* p = (StackNode*)malloc(sizeof(StackNode));
	if (p == NULL)
		return 0;
	p->data = data;//ͷ�巨
	p->next = s->top;
	s->top = p;
	s->count++;
	return 1;
}

//��ջ
Status popLStack(LinkStack *s,ElemType *data){
	if (s == NULL)
		return 0;
	StackNode* p = s->top; 
	if (p == NULL)
	{
		printf("ջ����Ԫ��\n");
		return 0;
	}
	else
	{
		s->top = p->next;//����Ųһλ
		*data = p->data;
		free(p);
		s->count--;
		return 1;
	}
}




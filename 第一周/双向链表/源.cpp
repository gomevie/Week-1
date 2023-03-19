#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node								//����һ���ṹ��
{
	char data[20];
	struct Node* next;
	struct Node* prev;
};

struct Node* InitNode()							//�½��µĽڵ� 
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));				//���ٿռ�
	if (!p)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	p->next = NULL;									//ʹ�ڵ�ΪNULL
	p->prev = NULL;
	return p;
}

struct Node* CreateList()			//����һ������, ����ͷ�ڵ� 
{
	int i, n;
	struct Node* head = InitNode();							//�Ƚ���һ����ͷ�ڵ�
	
	struct Node* pre = head;                    //����һ����ǰ�ڵ� 
	
	struct Node* front = head;                  //����һ����ǰ�ڵ�
	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ(�ûس�����)��");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//�����½ڵ�
		scanf("%s", (p->data));
		pre->next = p;
		pre = p;
		pre->prev = front;
		front = front->next;
	}
	return head;
}

int main()
{
	struct Node* list = CreateList();
	struct Node* pre = list;
	while (pre->next)                   //������������ֵ 
	{
		pre = pre->next;
		printf("%s\t", pre->data);
	}
	printf("\n");
	while (pre->prev)                   //������������ֵ 
	{
		printf("%s\t", pre->data);
		pre = pre->prev;
	}
}

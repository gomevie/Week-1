#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct Node								//����һ���ṹ��
{
	char data[20];
	struct Node* next;
};

struct Node* InitNode()							//�½��µĽڵ� 
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));				//���ٿռ�
	if (!p)
	{
		printf("�����ڴ�ʧ�ܣ�\n");
		exit(0);
	}
	p->next = NULL;									//ʹ�ڵ�nextΪNULL
	return p;
}

struct Node* CreateList()			//����һ��������, ����ͷ�ڵ� 
{
	int i, n;
	struct Node* head = InitNode();							//�Ƚ���һ����ͷ�ڵ�
	struct Node* prev = head;                    //����һ����ǰ�ڵ� 
	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf("%d", &n);
	printf("��������Ҫ�����Ԫ��ֵ(�ûس�����)��");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//�����½ڵ�
		scanf("%s", (p->data));
		prev->next = p;
		prev = p;
	}
	return head->next;
}

struct Node* trans(struct Node* list)
{
	if (list == NULL || list->next == NULL)
		return list;
	struct Node* pre = list;
	struct Node* head = pre->next;
	
	struct Node* prev = list;

	while (pre && pre->next)
	{
		struct Node* front = pre;
		pre = pre->next;
		prev->next = pre;
		front->next = pre->next;
		pre->next = front;
		pre = front->next;
		prev = front;
	}
	
	return head;
}

int main()
{
	struct Node* list = CreateList();
	list = trans(list);
	struct Node* prev = list;
	while (prev)                   //��������ֵ 
	{
		printf("%s\t", prev->data);
		prev = prev->next;
	}
}

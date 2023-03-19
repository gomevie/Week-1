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
	return head;
}

struct Node* Moddle(struct Node* list)
{
	if (list == NULL || list->next == NULL)
		return list;
	struct Node* fast = list;
	struct Node* slow = list;
	while (fast && fast->next)
	{                                           //���������, ������һ��
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

int main()
{
	struct Node* list = CreateList();
	struct Node* prev = list;
	while (prev->next)                   //��������ֵ 
	{
		prev = prev->next;
		printf("%s\t", prev->data);
	}
	printf("\n");
	struct Node* moddle = Moddle(list);
	printf("��ֵΪ%s", moddle->data);
}





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
	int i, n, m;
	struct Node* head = InitNode();							//�Ƚ���һ����ͷ�ڵ�
	struct Node* prev = head;                    //����һ����ǰ�ڵ� 
	printf("��������Ҫ����Ԫ�صĸ�����");
	scanf("%d", &n);
	printf("������Ҫ�ӵڼ����ڵ㿪ʼ�ǻ�(0��ʾ�޻�): ");
	scanf("%d", &m);
	if (n < m)
	{
		printf("��������\n");
		return NULL;
	}
	printf("��������Ҫ�����Ԫ��ֵ(�ûس�����)��");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//�����½ڵ�
		scanf("%s", (p->data));
		prev->next = p;
		prev = p;
	}
	struct Node* pre = head;
	for (i = 0; i < m; i++)
	{
		pre = pre->next;
	}
	prev->next = pre;
	if (m <= 0)
		prev->next = NULL;
	return head;
}

int IsCircle(struct Node* list)
{
	if (list == NULL)
		return 0;
	struct Node* fast = list;
	struct Node* slow = list;
	while (fast->next != NULL && fast->next->next != NULL)
	{
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			return 1;
	}
	return 0;
}

int main()
{
	struct Node* list = CreateList();
	struct Node* prev = list;
	int flag = IsCircle(list);
	if (flag == 1)
		printf("����һ���ɻ�����\n");
	if (flag == 0)
		printf("����һ���ǳɻ�����\n");
}

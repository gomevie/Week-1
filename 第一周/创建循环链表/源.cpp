#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node								//����һ���ṹ��
{
	char data[20];
	struct Node* next;
};


struct Node* creat_list()
{
	char item[20];
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));    //������ͷ�ڵ�
	head->next = NULL;
	strcpy(head->data, "null");
	struct Node* temp = head;
	printf("����ڵ��ֵ������Q/q����\n");
	while (1)
	{
		scanf("%s", &item);
		if (strcmp(item, "Q")==0 || strcmp(item, "q") == 0)
		{
			break;
		}
		else
		{
			struct Node* prev = (struct Node*)malloc(sizeof(struct Node));
			strcpy(prev->data, item);
			temp->next = prev;
			temp = prev;
		}
	}
	if (head->next == NULL)
	{
		head->next = head;
		return head;
	}
	else
	{
		return temp->next;                  //���ؿ�ͷ�ڵ����һ�ڵ�
		temp->next = head->next;             //ͷβ����
	}
}


int main()
{
	struct Node* list = creat_list();
	struct Node* prev = list;
	do                   //��������ֵ 
	{
		printf("%s\n", prev->data);
		prev = prev->next;
	} while (prev && prev != list);

}

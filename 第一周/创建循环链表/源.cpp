#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node								//定义一个结构体
{
	char data[20];
	struct Node* next;
};


struct Node* creat_list()
{
	char item[20];
	struct Node* head = (struct Node*)malloc(sizeof(struct Node));    //创建空头节点
	head->next = NULL;
	strcpy(head->data, "null");
	struct Node* temp = head;
	printf("输入节点的值，输入Q/q结束\n");
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
		return temp->next;                  //返回空头节点的下一节点
		temp->next = head->next;             //头尾相连
	}
}


int main()
{
	struct Node* list = creat_list();
	struct Node* prev = list;
	do                   //输出链表的值 
	{
		printf("%s\n", prev->data);
		prev = prev->next;
	} while (prev && prev != list);

}

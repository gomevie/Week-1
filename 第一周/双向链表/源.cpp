#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


struct Node								//定义一个结构体
{
	char data[20];
	struct Node* next;
	struct Node* prev;
};

struct Node* InitNode()							//新建新的节点 
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));				//开辟空间
	if (!p)
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	p->next = NULL;									//使节点为NULL
	p->prev = NULL;
	return p;
}

struct Node* CreateList()			//创建一个链表, 返回头节点 
{
	int i, n;
	struct Node* head = InitNode();							//先建立一个带头节点
	
	struct Node* pre = head;                    //定义一个当前节点 
	
	struct Node* front = head;                  //定义一个先前节点
	printf("请输入您要输入元素的个数：");
	scanf("%d", &n);
	printf("请输入你要输入的元素值(用回车隔开)：");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//生成新节点
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
	while (pre->next)                   //正向输出链表的值 
	{
		pre = pre->next;
		printf("%s\t", pre->data);
	}
	printf("\n");
	while (pre->prev)                   //反向输出链表的值 
	{
		printf("%s\t", pre->data);
		pre = pre->prev;
	}
}

#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>


struct Node								//定义一个结构体
{
	char data[20];
	struct Node* next;
};

struct Node* InitNode()							//新建新的节点 
{
	struct Node* p = (struct Node*)malloc(sizeof(struct Node));				//开辟空间
	if (!p)
	{
		printf("分配内存失败！\n");
		exit(0);
	}
	p->next = NULL;									//使节点next为NULL
	return p;
}

struct Node* CreateList()			//创建一个单链表, 返回头节点 
{
	int i, n;
	struct Node* head = InitNode();							//先建立一个带头节点
	struct Node* prev = head;                    //定义一个当前节点 
	printf("请输入您要插入元素的个数：");
	scanf("%d", &n);
	printf("请输入你要插入的元素值(用回车隔开)：");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//生成新节点
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
	while (prev)                   //输出链表的值 
	{
		printf("%s\t", prev->data);
		prev = prev->next;
	}
}

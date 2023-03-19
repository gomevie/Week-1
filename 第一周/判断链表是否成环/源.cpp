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
	int i, n, m;
	struct Node* head = InitNode();							//先建立一个带头节点
	struct Node* prev = head;                    //定义一个当前节点 
	printf("请输入您要插入元素的个数：");
	scanf("%d", &n);
	printf("请输入要从第几个节点开始城环(0表示无环): ");
	scanf("%d", &m);
	if (n < m)
	{
		printf("输入有误\n");
		return NULL;
	}
	printf("请输入你要插入的元素值(用回车隔开)：");
	for (i = 0; i < n; i++)
	{
		struct Node* p = InitNode();					//生成新节点
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
		printf("这是一个成环链表\n");
	if (flag == 0)
		printf("这是一个非成环链表\n");
}

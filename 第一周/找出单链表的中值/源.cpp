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
	return head;
}

struct Node* Moddle(struct Node* list)
{
	if (list == NULL || list->next == NULL)
		return list;
	struct Node* fast = list;
	struct Node* slow = list;
	while (fast && fast->next)
	{                                           //快的走两步, 慢的走一步
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
	while (prev->next)                   //输出链表的值 
	{
		prev = prev->next;
		printf("%s\t", prev->data);
	}
	printf("\n");
	struct Node* moddle = Moddle(list);
	printf("中值为%s", moddle->data);
}





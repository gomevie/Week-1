#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../head/LQueue.h" 


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if ((!Q->front) || (!Q->rear))
	{
		printf("队列初始化失败\n");
		exit(0);
	}
	Q->front->next = NULL;
	Q->front->data = 0;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
	Node* p;
	while (Q->front)
	{
		p = Q->front;
		Q->front = p->next;
		free(p);
	}
	Q->rear = Q->front;
	Q->length = 0;
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
	if (Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
Status GetHeadLQueue(LQueue* Q, void* e) {
	Node* p;
	if (Q->front == Q->rear)
		return FALSE;
	p = Q->front->next;
	
	if (type == 'i')
		*(int*)e = *(int*)(p->data);
	if (type == 'f')
		*(float*)e = *(float*)(p->data);
	if (type == 'c')
		*(char*)e = *(char*)(p->data);
	return TRUE;
}

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status LengthLQueue(LQueue* Q, int* length) {
	int i = 0;
	if (Q->front == NULL)
		return FALSE;
	Node* p;
	p = Q->front;
	while (p != Q->rear)
	{
		i++;
		p = p->next;
	}
	*length = i;
	return TRUE;
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
Status EnLQueue(LQueue* Q, void* data) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("入队操作失败,分配内存有误\n");
		return FALSE;
	}
	p->next = NULL;
	p->data = data;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q, void *data)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue* Q) {
	Node* p;
	if (Q->front == Q->rear)
		return FALSE;
	p = Q->front->next;
	Q->front->next = p->next;
	if (Q->rear == p)
		Q->rear = Q->front;
	free(p);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
	Node* p;
	Q->rear = Q->front;
	p = Q->front->next;
	Q->front->next = NULL;
	while (p)
	{
		Node* q;
		q = p;
		p = p->next;
		free(q);
	}
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue* Q, void (*foo)(void* q)) {
	if (Q->front == Q->rear)
		return FALSE;
	Node* p = Q->front->next;
	while (p != NULL)
	{
		foo(p->data);
		p = p->next;
	}
	return TRUE;
}

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q

 *  @notice      : None
 */
void LPrint(void* q) {
	if (type == 'i')
		printf("%d\n", *(int*)q);
	if (type == 'f')
		printf("%f\n", *(float*)q);
	if (type == 'c')
		printf("%c\n", *(char*)q);

}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
 // LQUEUE_H_INCLUDED



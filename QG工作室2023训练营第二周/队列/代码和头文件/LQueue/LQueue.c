#define _CRT_SECURE_NO_WARNINGS


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "../head/LQueue.h" 


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
	Q->front = Q->rear = (Node*)malloc(sizeof(Node));
	if ((!Q->front) || (!Q->rear))
	{
		printf("���г�ʼ��ʧ��\n");
		exit(0);
	}
	Q->front->next = NULL;
	Q->front->data = 0;
	Q->length = 0;
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
Status EnLQueue(LQueue* Q, void* data) {
	Node* p = (Node*)malloc(sizeof(Node));
	if (p == NULL)
	{
		printf("��Ӳ���ʧ��,�����ڴ�����\n");
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
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
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
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
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
 *    @description : ��������
 *    @param         q ָ��q

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



#include "SList.h"

//��ӡ���� 
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}

//�����ڴ�
SLTNode* BuySListNode(SListDataType x) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//β��
void SListPushBack(SLTNode** pphead, SListDataType x) {
	//�ص㣺���ﻹ�ǿ�ָ�룡����
	
	SLTNode* newNode=BuySListNode(x);	
	if (*pphead == NULL) {
		
		*pphead = newNode;

	}
	//�ҵ�β
	else {
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//ָ����һ���ڵ�
		tail->next = newNode;
	}
		
}
//βɾ
void SListPopBack(SLTNode** pphead) {
	if (*pphead == NULL) {
		return;
	}
	else if ((*pphead)->next==NULL) {
		free(*pphead);
		*pphead = NULL;
	}
	else {
		SLTNode* tail=*pphead;
		SLTNode* prev=NULL;
		while (tail->next!= NULL) {
			prev = tail;
			tail= tail->next;
		}
		free(tail);
		prev->next = NULL;
	}
}
//ͷ��
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode; 
}


//ͷɾ
void SListPopFront(SLTNode** pphead)
{
	if (*pphead == NULL)
	{
		return;
	}
	else
	{
		SLTNode* next = (*pphead)->next;
		free(*pphead);
		*pphead = next;
	}
}

//����
SLTNode* SListFind(SLTNode* pphead, SListDataType x)
{
	SLTNode* cur = pphead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
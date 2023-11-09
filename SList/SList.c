#include "SList.h"

//打印函数 
void SListPrint(SLTNode* phead) {
	SLTNode* cur = phead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur=cur->next;
	}
	printf("NULL\n");
}

//申请内存
SLTNode* BuySListNode(SListDataType x) {
	SLTNode* newNode = (SLTNode*)malloc(sizeof(SLTNode));
	if (newNode == NULL) {
		printf("申请内存失败\n");
		exit(-1);
	}
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

//尾插
void SListPushBack(SLTNode** pphead, SListDataType x) {
	//重点：这里还是空指针！！！
	
	SLTNode* newNode=BuySListNode(x);	
	if (*pphead == NULL) {
		
		*pphead = newNode;

	}
	//找到尾
	else {
		SLTNode* tail = *pphead;
		while (tail->next != NULL) {
			tail = tail->next;
		}
		//指向下一个节点
		tail->next = newNode;
	}
		
}
//尾删
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
//头插
void SListPushFront(SLTNode** pphead, SListDataType x)
{
	SLTNode* newNode = BuySListNode(x);
	newNode->next = *pphead;
	*pphead = newNode; 
}


//头删
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

//查找
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
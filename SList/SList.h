#pragma once
#include <stdio.h>
#include <stdlib.h>

typedef int SListDataType;

typedef struct SListNode {
	SListDataType data;
	struct SListNode* next;
}SLTNode;


void SListPushBack(SLTNode** pphead, SListDataType x);
void SListPopBack(SLTNode** pphead);
void SListPushFront(SLTNode** pphead, SListDataType x);
void SListPopFront(SLTNode** pphead);

void SListPrint(SLTNode* phead);
SLTNode* BuySListNode(SListDataType x);
SLTNode* SListFind(SLTNode* pphead, SListDataType x);
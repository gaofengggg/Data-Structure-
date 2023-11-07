#include "SeqList.h"
#include <stdio.h>


void Test()
{
	//测试各个函数接口
	SL s;
	SeqListInit(&s);           
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPrint(&s);
	
	SeqListPushBack(&s, 33);
	SeqListPushBack(&s, 33);
	SeqListPushBack(&s, 33);
	SeqListPrint(&s);
	
	SeqListPushFront(&s, -9);
	SeqListPushFront(&s, -9);
	SeqListPushFront(&s, -9);
	SeqListPrint(&s);
	
	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPrint(&s);
	
	SeqListPopFront(&s);
	SeqListPrint(&s);

	SeqListInsert(&s, 3, 1000);
	SeqListInsert(&s, 2, 500);
	SeqListPrint(&s);

	SeqListErase(&s, 5);
	SeqListErase(&s, 2);
	SeqListPrint(&s);

	SeqListFind(&s, 1000);
	SeqListPrint(&s);

	SeqListModify(&s, 3, 666);
	SeqListPrint(&s);

}
int main()
{
	Test();
	return 0;
}
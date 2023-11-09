#include "SList.h"
void test01() {
	SLTNode* pList = NULL;

	SListPushBack(&pList, 3);
	SListPushBack(&pList, 4);
	SListPushBack(&pList, 5);
	SListPushBack(&pList, 6);
	SListPrint(pList);

	SListPopBack(&pList);
	SListPopBack(&pList);
	SListPrint(pList);

	SListPushFront(&pList, 6);
	SListPushFront(&pList, 5);
	SListPushFront(&pList, 4);
	SListPrint(pList);

	SLTNode* pos= SListFind(pList,6);
	if (pos)
	{
		pos->data = 666;
	}
	SListPrint(pList);


}

int main() {
	
	test01();
	
	return 0;
}
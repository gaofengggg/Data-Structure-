#define _CRT_SECURE_NO_WARNINGS 1

#include "Seqlist.h"

void SeqListPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SeqListInit(SL* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->size = 0;
}

void SeqListDestory(SL* ps)
{
	assert(ps);
	if (ps->a)
	{
		free(ps->a);
		ps->a = NULL;
		ps->capacity = ps->size = 0;
	}
}

void SeqListCheckCapacity(SL* ps)
{
	if (ps->capacity == ps->size)
	{
		int newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
		SLDataType* tmp = (SLDataType*)realloc(ps->a, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			return;
		}
		ps->capacity = newCapacity;
		ps->a = tmp;
	}
}

void SeqListPushBack(SL* ps, SLDataType x)
{
	//assert(ps);
	//SLCheckCapacity(ps);

	//ps->a[ps->size] = x;
	//ps->size++;
	SeqListInsert(ps, ps->size, x);
}

void SeqListPushFront(SL* ps, SLDataType x)
{
	//assert(ps);
	//SLCheckCapacity(ps);

	//int end = ps->size;
	//while (end > 0)
	//{
	//	ps->a[end] = ps->a[end - 1];
	//	end--;
	//}
	//ps->a[end] = x;
	//ps->size++;
	SeqListInsert(ps, 0, x);
}

void SeqListPopBack(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);
	//ps->size--;
	SeqListErase(ps, ps->size - 1);
}

void SeqListPopFront(SL* ps)
{
	//assert(ps);
	//assert(ps->size > 0);

	//int end = ps->size - 1;
	//for (int i = 0; i < end; i++)
	//{
	//	ps->a[i] = ps->a[i + 1];
	//}
	//ps->size--;
	SeqListErase(ps, 0);
}

void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SeqListCheckCapacity(ps);

	//pos就是插入的下标
	int end = ps->size;
	while (end > pos)
	{
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
}

void SeqListErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->a[i] = ps->a[i + 1];
	}
	ps->size--;
}

int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			printf("%d\n", i);
			return i;
		}
	}
	printf("没找到\n");
	return -1;
}

void SeqListModify(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos < ps->size);

	ps->a[pos-1] = x;
}
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* a;//指向动态开辟的数组
	int size;     //表中已存入数据的个数
	int capacity; //容量空间的大小
}SL;

//初始化
void SeqListInit(SL* ps);
//销毁
void SeqListDestory(SL* ps);
//打印
void SeqListPrint(SL* ps);


//尾插
void SeqListPushBack(SL* ps, SLDataType x);
//头插
void SeqListPushFront(SL* ps, SLDataType x);
//尾删
void SeqListPopBack(SL* ps);
//头删
void SeqListPopFront(SL* ps);
//中间插入
void SeqListInsert(SL* ps, int pos, SLDataType x);
//中间删除
void SeqListErase(SL* ps, int pos);


//检查扩容
void SeqListCheckCapacity(SL* ps);
//查找
int SeqListFind(SL* ps, SLDataType x);
//修改
void SeqListModify(SL* ps, int pos, SLDataType x);
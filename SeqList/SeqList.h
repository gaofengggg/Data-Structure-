#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

typedef struct Seqlist
{
	SLDataType* a;//ָ��̬���ٵ�����
	int size;     //�����Ѵ������ݵĸ���
	int capacity; //�����ռ�Ĵ�С
}SL;

//��ʼ��
void SeqListInit(SL* ps);
//����
void SeqListDestory(SL* ps);
//��ӡ
void SeqListPrint(SL* ps);


//β��
void SeqListPushBack(SL* ps, SLDataType x);
//ͷ��
void SeqListPushFront(SL* ps, SLDataType x);
//βɾ
void SeqListPopBack(SL* ps);
//ͷɾ
void SeqListPopFront(SL* ps);
//�м����
void SeqListInsert(SL* ps, int pos, SLDataType x);
//�м�ɾ��
void SeqListErase(SL* ps, int pos);


//�������
void SeqListCheckCapacity(SL* ps);
//����
int SeqListFind(SL* ps, SLDataType x);
//�޸�
void SeqListModify(SL* ps, int pos, SLDataType x);
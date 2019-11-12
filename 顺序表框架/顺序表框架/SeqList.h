#ifndef _SEQLIST_H__
#define _SEQLIST_H__
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int Datetype;
typedef struct SeqList
{
	Datetype* _a;
	size_t    capacity;
	size_t    size;
}SeqList;
void SeqListInit(SeqList* s1, size_t capacity);
void SeqListDestory(SeqList* s1);
void SeqListCheck(SeqList* s1);
void SeqListPushBack(SeqList* s1, Datetype num);
void SeqListPopBack(SeqList* s1);
void SeqListPushFront(SeqList* s1, Datetype num);
void SeqListPopFront(SeqList* s1);
int SeqListFind(SeqList* s1, Datetype num);
void SeqListInsert(SeqList* s1, size_t poss, Datetype num);
void SeqListErase(SeqList* s1, size_t poss);
void SeqListPrint(SeqList* s1);
void SeqListRemove(SeqList* s1, Datetype num);
void SeqListBubbleSort(SeqList* s1);
int  SeqListBinaryFind(SeqList* psl, Datetype x);
void SeqListRemoveAll(SeqList* psl, Datetype x);// 时间复杂度：O(N) 空间复杂度 O(1)
#endif
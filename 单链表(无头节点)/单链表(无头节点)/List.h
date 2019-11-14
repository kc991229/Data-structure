#ifndef _LIST_H__
#define _LIST_H__
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int DateType;

typedef struct PlistNode
{
	DateType _date;
	struct PlistNode* _next;
}PlistNode;

PlistNode* GetNode(DateType x);
void PushBack(PlistNode** pplist, DateType x);
void PopBack(PlistNode** pplist);
void PushFront(PlistNode** pplist, DateType x);
void PopFront(PlistNode** pplist);
//SListNode*SListFind(SList*plist, SLTDataTypex);
////��pos�ĺ�����в��� 
//voidSListInsertAfter(SListNode*pos, SLTDataTypex);//��pos��ǰ����в��� 
//voidSListEraseAfter(SListNode*pos);
//voidSListRemove(SList*plist, SLTDataTypex);
void Print(PlistNode* plist);

#endif
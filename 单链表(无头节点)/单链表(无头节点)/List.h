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
PlistNode* ListFind(PlistNode* plist, DateType x);
void ListInsertAfter(PlistNode** pos, DateType x);
void SListEraseAfter(PlistNode** pos);
void Print(PlistNode* plist);

PlistNode* removeElements(PlistNode** head, int val);
PlistNode* reverseList(PlistNode** head);
PlistNode* reverseList1(PlistNode** head);
PlistNode* middleNode(PlistNode** head);
PlistNode* FindKNode(PlistNode** head, int k);
int ChkPalindrome(PlistNode* head);
int ChkPalindrome1(PlistNode* head);
PlistNode* mergeTwoLists(PlistNode** l1, PlistNode** l2);
PlistNode* deleteDuplication(PlistNode* pHead);

#endif
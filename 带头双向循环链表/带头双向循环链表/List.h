#ifndef _LIST_H_
#define _LIST_H_
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
typedef int DateType;

typedef struct ListNode
{
	DateType _date;
	struct ListNode* _next;
	struct ListNode* _prev;

}ListNode;

ListNode* CreateHead();
ListNode* CreateNode(DateType x);
void EraseList(ListNode** plist);
void PopList(ListNode* plist);
void ListPrint(ListNode* plist);
void PushBack(ListNode* plist, DateType x);
void PushFront(ListNode* plist, DateType x);
void PopBack(ListNode* plist);
void PopFront(ListNode* plist);
ListNode* ListFind(ListNode* plist, DateType x);
void ListInsert(ListNode* pos, DateType x);
void ListErase(ListNode* pos);

#endif
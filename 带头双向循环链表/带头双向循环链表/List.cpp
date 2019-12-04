#include "List.h"
/*
函数功能：创立一个头节点
入口参数：无
返回值：头节点的地址
*/
ListNode* CreateHead()
{
	ListNode* newhead = (ListNode*)malloc((sizeof(ListNode)));
	newhead->_next = newhead;
	newhead->_prev = newhead;
	return newhead;
}
/*
函数功能：创立一个新的节点，并赋予_date新值
入口参数：要赋予的值
返回值：新节点的地址
*/
ListNode* CreateNode(DateType x)
{
	ListNode* newnode = (ListNode*)malloc((sizeof(ListNode)));
	newnode->_next = NULL;
	newnode->_prev = NULL;
	newnode->_date = x;
	return newnode;
}
/*
函数功能：删除链表
入口参数：该链表头的地址
返回值：无
*/
void EraseList(ListNode** plist)
{
	assert(plist);
	ListNode* head = (*plist);
	ListNode* cur = ((*plist));
	ListNode* tmp = ((*plist)->_next);
	if (tmp == head)
	{
		;
	}
	else
	{
		while (tmp != head)
		{
			cur = tmp;
			tmp = tmp->_next;
			free(cur);

		}
		tmp = NULL;
	}
	(*plist)->_next = (*plist);
	(*plist)->_prev = (*plist);
}
/*
函数功能：打印函数
入口参数：链表的头节点
返回值：无
*/
void ListPrint(ListNode* plist)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur != plist)
	{
		printf("%d\n", cur->_date); 
		cur=cur->_next;
	}
	printf("NULL");
	printf("\n");
	printf("\n");
}
/*
函数功能：尾插
入口参数：链表头节点、要插入的值
返回值：无
*/
void PushBack(ListNode* plist, DateType x)
{
	assert(plist);
	ListNode* newnode = CreateNode(x);
	if (plist->_next == plist)
	{
		plist->_next = newnode;
		plist->_prev = newnode;
		newnode->_next = plist;
		newnode->_prev = plist;
	}
	else
	{
		newnode->_next = plist->_prev->_next;
		newnode->_prev = plist->_prev;
		plist->_prev->_next = newnode;
		newnode->_next->_prev = newnode;
	}

}
/*
函数功能：头插
入口参数：链表头节点地址、要插入的值
返回值：无
*/
void PushFront(ListNode* plist, DateType x)
{
	assert(plist);
	ListNode* newnode = CreateNode(x);
	plist->_next->_prev = newnode;
	newnode->_next = plist->_next;
	plist->_next = newnode;
	newnode->_prev = plist;
}
/*
函数功能：尾删
入口参数：链表头节点
返回值：无
*/
void PopBack(ListNode* plist)
{
	assert(plist);
	if (plist->_next == plist)
	{
		;
	}
	else
	{
		ListNode* cur = plist->_prev;
		plist->_prev->_prev->_next = plist;
		plist->_prev = plist->_prev->_prev;
		free(cur);
		cur = NULL;
	}
}
/*
函数功能：头删
入口参数：链表头节点
返回值：无
*/
void PopFront(ListNode* plist)
{
	assert(plist);
	if (plist->_next == plist)
		;
	else
	{
		ListNode* cur = plist->_next;
		plist->_next->_next->_prev = plist;
		plist->_next = plist->_next->_next;
		free(cur);
		cur = NULL;
	}
}
/*
函数功能：查找函数
入口参数：链表头节点、要寻找的值
返回值：所查找的值在链表中的第一个节点地址
*/
ListNode* ListFind(ListNode* plist, DateType x)
{
	assert(plist);
	ListNode* cur = plist->_next;
	while (cur->_date != x)
	{
		cur = cur->_next;
	}
	return cur;
}
/*
函数功能：插入函数
入口参数：要插入的节点地址、要插入的值
返回值：无
*/
void ListInsert(ListNode* pos, DateType x)
{
	assert(pos);
	ListNode* newnode = CreateNode(x);
	newnode->_next = pos;
	newnode->_prev = pos->_prev;
	pos->_prev = newnode;
	newnode->_prev->_next = newnode;
}
/*
函数功能：删除节点寒素
入口参数：链表头地址
返回值：无
*/
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
}
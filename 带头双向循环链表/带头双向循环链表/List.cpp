#include "List.h"
/*
�������ܣ�����һ��ͷ�ڵ�
��ڲ�������
����ֵ��ͷ�ڵ�ĵ�ַ
*/
ListNode* CreateHead()
{
	ListNode* newhead = (ListNode*)malloc((sizeof(ListNode)));
	newhead->_next = newhead;
	newhead->_prev = newhead;
	return newhead;
}
/*
�������ܣ�����һ���µĽڵ㣬������_date��ֵ
��ڲ�����Ҫ�����ֵ
����ֵ���½ڵ�ĵ�ַ
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
�������ܣ�ɾ������
��ڲ�����������ͷ�ĵ�ַ
����ֵ����
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
�������ܣ���ӡ����
��ڲ����������ͷ�ڵ�
����ֵ����
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
�������ܣ�β��
��ڲ���������ͷ�ڵ㡢Ҫ�����ֵ
����ֵ����
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
�������ܣ�ͷ��
��ڲ���������ͷ�ڵ��ַ��Ҫ�����ֵ
����ֵ����
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
�������ܣ�βɾ
��ڲ���������ͷ�ڵ�
����ֵ����
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
�������ܣ�ͷɾ
��ڲ���������ͷ�ڵ�
����ֵ����
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
�������ܣ����Һ���
��ڲ���������ͷ�ڵ㡢ҪѰ�ҵ�ֵ
����ֵ�������ҵ�ֵ�������еĵ�һ���ڵ��ַ
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
�������ܣ����뺯��
��ڲ�����Ҫ����Ľڵ��ַ��Ҫ�����ֵ
����ֵ����
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
�������ܣ�ɾ���ڵ㺮��
��ڲ���������ͷ��ַ
����ֵ����
*/
void ListErase(ListNode* pos)
{
	assert(pos);
	pos->_next->_prev = pos->_prev;
	pos->_prev->_next = pos->_next;
	free(pos);
}
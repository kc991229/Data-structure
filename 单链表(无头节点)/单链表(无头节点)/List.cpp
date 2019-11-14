#include "List.h"

PlistNode* GetNode(DateType x)
{
	PlistNode* NewNode = (PlistNode*)malloc(sizeof(PlistNode));
	NewNode->_date = x;
	NewNode->_next = NULL;
	return NewNode;
}
void PushBack(PlistNode** pplist, DateType x)
{
	PlistNode* NewNode = GetNode(x);
	if (*pplist == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		PlistNode* tail = *pplist;
		while (tail->_next != NULL)
		{
			tail = tail->_next;
		}
		tail->_next = NewNode;
	}

}
void PopBack(PlistNode** pplist)
{
	//两情况：只有一个或零个数据、多个数据
	if (*pplist == NULL || (*pplist)->_next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		PlistNode* cur = *pplist;
		PlistNode* prv = NULL;
		while (cur->_next)
		{
			prv = cur;
			cur = cur->_next;
		}
		free(cur);
		cur = NULL;
		prv->_next = NULL;
	}
}
void PushFront(PlistNode** pplist, DateType x)
{
	PlistNode* NewNode = GetNode(x);
	if (*pplist == NULL)
	{
		*pplist = NewNode;
	}
	else
	{
		NewNode->_next = *pplist;
		*pplist = NewNode;
	}
}
void PopFront(PlistNode** pplist)
{
	//无、一个、多个
	if (*pplist == NULL)
	{
		return;
	}
	else if ((*pplist)->_next == NULL)
	{
		free(*pplist);
		*pplist = NULL;
	}
	else
	{
		PlistNode* cur = (*pplist)->_next;
		free(*pplist);
		*pplist = cur;
	}
}
void Print(PlistNode* plist)
{
	PlistNode* cur = plist;
	while (cur != NULL)
	{
		printf("%d\n", cur->_date);
		cur = cur->_next;
	}
	printf("\n");
}

#include "List.h"
/*
�������ܣ��õ�һ���µĽڵ㣬����Ҫ�����ֵ�����ýڵ�
��ڲ�����Ҫ�����ֵ
����ֵ���½ڵ��ָ��
*/
PlistNode* GetNode(DateType x)
{
	PlistNode* NewNode = (PlistNode*)malloc(sizeof(PlistNode));
	NewNode->_date = x;
	NewNode->_next = NULL;
	return NewNode;
}
/*
�������ܣ�β�巨
��ڲ�����ĳ�����ͷ�ĵ�ַ��Ҫ�����ֵ
����ֵ����
*/
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
/*
�������ܣ�βɾ��
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ����
*/
void PopBack(PlistNode** pplist)
{
	//�������ֻ��һ����������ݡ��������
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
/*
�������ܣ�ͷ�巨
��ڲ�����ĳ�����ͷ�ĵ�ַ��Ҫ�����ֵ
����ֵ����
*/
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
/*
�������ܣ�ͷ�巨
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ����
*/
void PopFront(PlistNode** pplist)
{
	//�ޡ�һ�������
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
/*
�������ܣ����Һ���
��ڲ�����ĳ�����ͷ�ĵ�ַ��Ҫ���ҵ�ֵ
����ֵ����
*/
PlistNode* ListFind(PlistNode* plist, DateType x)
{
	assert(plist);
	PlistNode* cur = plist;
	while (cur != NULL)
	{
		if (x == cur->_date)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}
/*
�������ܣ���һ�������posλ�����
��ڲ�����һ�������ĳһ���ڵ㣬Ҫ�����ֵ
����ֵ����
*/
void ListInsertAfter(PlistNode** pos, DateType x)
{
	PlistNode* cur = GetNode(x);
	PlistNode* tmp = NULL;
	tmp = (*pos)->_next;
	(*pos)->_next = cur;
	cur->_next = tmp;
}
/*
�������ܣ�ɾ��ĳ������pos���һ���ڵ�
��ڲ�����һ�������ĳ���ڵ�
����ֵ����
*/
void SListEraseAfter(PlistNode** pos)
{
	PlistNode* tmp = NULL;
	PlistNode* cur = NULL;
	tmp = (*pos)->_next;
	cur = tmp->_next;
	(*pos)->_next = cur;
	free(tmp);
	tmp = NULL;
}/*
 �������ܣ���ӡ����
 ��ڲ�����ĳ�����ͷ�ĵ�ַ
 ����ֵ����
 */
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

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
�������ܣ�ͷɾ��
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
/*
�������ܣ�Ѱ�������ཻ����Ľ���
��ڲ���������A��ͷ������B��ͷ
����ֵ��NULL||�ཻ�ڵ��ָ��
*/
PlistNode *getIntersectionNode(PlistNode *headA,  PlistNode* headB)
{
	if (headA == NULL || headB == NULL)
		return NULL;
	PlistNode* n1 = headA;
	PlistNode* n2 = headB;
	int num1 = 0, num2 = 0, count = 0;
	while (n1)
	{
		num1++;
		n1 = n1->_next;
	}
	while (n2)
	{
		num2++;
		n2 = n2->_next;
	}
	if (n1 != n2)
		return NULL;
	count = abs(num1 - num2);
	n1 = headA;
	n2 = headB;
	if (num1>num2)
	{
		while (count--)
		{
			n1 = n1->_next;
		}
	}
	else{
		while (count--)
		{
			n2 = n2->_next;
		}
	}
	while (n1 != n2)
	{
		n1 = n1->_next;
		n2 = n2->_next;
	}
	return n1;
}
/*
�������ܣ��ж�һ�������Ƿ��л�
��ڲ�����һ�������ͷ
����ֵ��true||false
*/
bool hasCycle(PlistNode *head)
{
	if (head == NULL || head->_next == NULL)
		return 0;
	PlistNode* fast = head->_next->_next;
	PlistNode* slow = head->_next;
	while (fast != slow&&fast&&fast->_next)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
	}
	if (fast == NULL || fast->_next == NULL)
	{
		return 0;
	}
	else
		return 1;
}
/*
�������ܣ�Ѱ��������뻷��
��ڲ�����һ�������ͷ
����ֵ��NULL||�뻷�㴦��ָ��
*/
PlistNode *detectCycle(PlistNode *head) 
{
	if (head == NULL || head->_next == NULL)
		return NULL;
	//�ų����������Ϊ�ջ�ֻ��һ���ڵ�

	PlistNode* fast = head->_next->_next;//��ָ��������
	PlistNode* slow = head->_next;//��ָ����һ��
	while (fast != slow && fast&& fast->_next)//������ж�˳�����ң���Ȼ�����bug
	{
		fast = fast->_next->_next;
		slow = slow->_next;
	}

	if (fast == NULL || fast->_next == NULL)
	{
		return NULL;
	}
	//�жϵ������޻������

	else{
		slow = head;//��һ��ָ��������ͷ��ʼ
		while (slow != fast)//��������ʱ����ǻ���ڵ�
		{
			slow = slow->_next;
			fast = fast->_next;
		}
		return fast;
	}
}
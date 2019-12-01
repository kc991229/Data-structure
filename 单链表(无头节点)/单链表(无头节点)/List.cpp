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
/*
�������ܣ�ɾ�������е�����val
��ڲ�����ĳ�����ͷ�ĵ�ַ��Ҫɾ����val
����ֵ�������������ͷ
*/
PlistNode* removeElements(PlistNode** head, int val)
{
	PlistNode* cur = *head;
	PlistNode* tmp = NULL;
	PlistNode* newhead = *head;
	while (cur != NULL)
	{
		if (cur->_date != val)
		{
			tmp = cur;
			cur = cur->_next;
		}
		else
		{
			if (tmp == NULL)
			{
				newhead = cur->_next;
				free(cur);
				cur = newhead;
			}
			else
			{
				tmp->_next = cur->_next;
				free(cur);
				cur = tmp->_next;
			}
		}
	}
	return newhead;
}
/*
�������ܣ���ת����(��̬����ͷ�巨)
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ����ת������������ͷ
*/
PlistNode* reverseList(PlistNode** head)
{
	if ((*head) == NULL || (*head)->_next == NULL)
		return (*head);
	PlistNode* cur = *head;
	PlistNode* newhead = GetNode(cur->_date);
	PlistNode* tmp = NULL;
	do
	{
		cur = cur->_next;
		tmp = GetNode(cur->_date);
		tmp->_next = newhead;
		newhead = tmp;
	} while (cur->_next != NULL);
	return newhead;
}
/*
�������ܣ���ת����(��ָ�����÷�)
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ����ת�����������ͷ
*/
PlistNode* reverseList1(PlistNode** head)
{
	if ((*head == NULL) || ((*head)->_next == NULL))
		return *head;
	PlistNode* n1 = (*head);
	PlistNode* n2 = (*head)->_next;
	PlistNode* n3 = n2->_next;
	n1->_next = NULL;
	while (n2 != NULL)
	{
		n2->_next = n1;
		n1 = n2;
		n2 = n3;
		if (n3 != NULL)
			n3 = n3->_next;
	}
	return n1;
}
/*
�������ܣ�Ѱ��������м�λ��
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ���м�λ�õĵ�ַ
*/
PlistNode* middleNode(PlistNode** head)
{
	PlistNode* fast = *head;
	PlistNode* slow = *head;
	while (fast != NULL&&fast->_next != NULL)
	{
		fast = fast->_next->_next;
		slow = slow->_next;
	}
	return slow;
}
/*
�������ܣ�Ѱ������ĵ�K���ڵ�
��ڲ�����ĳ�����ͷ�ĵ�ַ��ҪѰ�ҵ�Kֵ
����ֵ��K�ĵ�ַ
*/
PlistNode* FindKNode(PlistNode** head, int k)
{
	if ((*head) == NULL)
		return NULL;
	PlistNode* fast = *head;
	PlistNode* slow = *head;
	while (k--)
	{
		if (fast == NULL)
			return NULL;
		fast = fast->_next;
	}
	while (fast != NULL)
	{
		fast = fast->_next;
		slow = slow->_next;
	}
	return slow;
}
/*
�������ܣ��ж������Ƿ�Ϊ���Ľṹ
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ��1��0
*/
int ChkPalindrome(PlistNode* head)
{
	if (head == NULL)
	{
		return 1;
	}
	if (head->_next == NULL)
		return 1;
	if (head->_next->_next == NULL)
	{
		if (head->_date == head->_next->_date)
			return 1;
		else
			return 0;
	}
	//Ѱ���м�ڵ�
	PlistNode* n1 = head;
	PlistNode* n2 = head;
	while (n2 != NULL && n2->_next != NULL)
	{
		n1 = n1->_next;
		n2 = n2->_next;
		n2 = n2->_next;
	}
	n2 = head;

	//���ú�벿������
	PlistNode* a1 = n1;
	PlistNode* a2 = a1->_next;
	PlistNode* a3 = a2->_next;
	a1->_next = NULL;
	while (a2 != NULL)
	{
		a2->_next = a1;
		a1 = a2;
		a2 = a3;
		if (a3 != NULL)
			a3 = a3->_next;
	}
	n1 = a1;
	a1 = a2 = a3 = NULL;

	//���бȶ�
	while (n1 != NULL&&n2 != NULL)
	{
		if (n1->_date != n2->_date)
			return 0;
		n1 = n1->_next;
		n2 = n2->_next;
	}
	return 1;
}
/*
�������ܣ��ж������Ƿ�Ϊ���Ľṹ
��ڲ�����ĳ�����ͷ�ĵ�ַ
����ֵ��1��0
*/
int ChkPalindrome1(PlistNode* head)
{
	if (head == NULL)
	{
		return 1;
	}
	PlistNode* n1 = head;
	PlistNode* n2 = head;
	int arr[900];
	int count = 0;
	while (n2 != NULL)
	{
		arr[count++] = n2->_date;
		n2 = n2->_next;
	}
	count--;
	n2 = NULL;
	while (n1 != NULL)
	{
		if (n1->_date != arr[count--])
			return 0;
		n1 = n1->_next;
	}
	return 1;
}
/*
�������ܣ������������������ԭ�غϲ�
��ڲ���������1ͷ�ĵ�ַ������2ͷ�ĵ�ַ
����ֵ���ϲ����������ͷ
*/
PlistNode* mergeTwoLists(PlistNode** l1, PlistNode** l2)
{
	if (*l1 == NULL)
		return *l2;
	else if (*l2 == NULL)
		return *l1;
	PlistNode* n1 = *l1;
	PlistNode* n2 = *l2;
	PlistNode* n3 = NULL;
	PlistNode* cur = NULL;
	PlistNode* head = NULL;

	//����ͷ
	if (n1->_date >= n2->_date)
	{
		cur = n2->_next; //��¼n2����һ������

		n3 = n2;
		n2->_next = n1;//˫ָ�빹��

		n2 = cur;//n2��ǰ�ƶ�
	}
	else
	{
		n3 = n1;
		n1 = n1->_next;  //����˫ָ��
	}
	head = n3;//��ͷ�Ա���

	//˫ָ�뷨�����¹���
	while ((n1 != NULL) && (n2 != NULL))
	{
		if ((n2->_date >= n3->_date) && (n2->_date <= n1->_date))
		{
			cur = n2->_next;//����n2����һ����

			n3->_next = n2;
			n2->_next = n1;
			n3 = n3->_next;  //˫ָ����ǰ�ƶ�

			n2 = cur;//n2��ǰ�ƶ�
		}
		else{
			n3 = n1;
			n1 = n1->_next;  //˫ָ����ǰ�ƶ�
		}
	}

	//�ų��������
	if (n2 != NULL)
	{
		n3->_next = n2;//ֱ��β�弴��
	}
	return head;
}
/*
�������ܣ����������ظ�Ԫ��ɾ��
��ڲ����������ͷ
����ֵ���������������ͷ
*/
PlistNode* deleteDuplication(PlistNode* pHead)
{
	if (pHead == NULL)
		return NULL;
	PlistNode* n2 = pHead;
	PlistNode* n1 = pHead->_next;
	PlistNode* newhead = NULL;
	PlistNode* cur = NULL;
	PlistNode* tmp = NULL;
	newhead = tmp;
	int num = 1;
	int k = (pHead->_date) - 1;
	if (n1 == NULL)
	{
		return pHead;
	}
	else if (n1->_next == NULL)
	{
		if (n1->_date != n2->_date)
			return pHead;
		else
			return NULL;
	}
	while (n1&&n1->_next)
	{
		if (n1->_date == n2->_date)
		{
			k = n1->_date;
			n2 = n1->_next;
			n1 = n2->_next;
		}
		else if (n2->_date == k)
		{
			n2 = n1;
			n1 = n1->_next;
		}
		else
		{
			if (num)
			{
				cur = (PlistNode*)malloc(sizeof(PlistNode));
				cur->_date = n2->_date;
				cur->_next = NULL;
				tmp = cur;
				newhead = cur;
				n2 = n1;
				n1 = n1->_next;
				num--;
			}
			else{
				cur = (PlistNode*)malloc(sizeof(PlistNode));
				cur->_date = n2->_date;
				cur->_next = NULL;
				tmp->_next = cur;
				tmp = cur;
				n2 = n1;
				n1 = n1->_next;
			}
		}
	}
	if (n2 != NULL&&n1 != NULL)
	{
		if (n2->_date != n1->_date&&n2->_date != k)
		{
			tmp->_next = n2;
		}
		else if (n2->_date != n1->_date&&n2->_date == k)
		{
			tmp->_next = n1;
		}
	}
	else if (n1 == NULL&&n2 != NULL)
	{
		if (n2->_date != k)
			tmp->_next = n2;
	}
	return newhead;
}
#include "List.h"
/*
函数功能：得到一个新的节点，并将要插入得值赋给该节点
入口参数：要插入得值
返回值：新节点的指针
*/
PlistNode* GetNode(DateType x)
{
	PlistNode* NewNode = (PlistNode*)malloc(sizeof(PlistNode));
	NewNode->_date = x;
	NewNode->_next = NULL;
	return NewNode;
}
/*
函数功能：尾插法
入口参数：某链表的头的地址，要插入的值
返回值：无
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
函数功能：尾删法
入口参数：某链表的头的地址
返回值：无
*/
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
/*
函数功能：头插法
入口参数：某链表的头的地址，要插入的值
返回值：无
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
函数功能：头删法
入口参数：某链表的头的地址
返回值：无
*/
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
/*
函数功能：查找函数
入口参数：某链表的头的地址，要查找的值
返回值：无
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
函数功能：在一个链表的pos位后插入
入口参数：一个链表的某一个节点，要插入的值
返回值：无
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
函数功能：删除某个链表pos后的一个节点
入口参数：一个链表的某个节点
返回值：无
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
 函数功能：打印函数
 入口参数：某链表的头的地址
 返回值：无
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
函数功能：删除链表中的所有val
入口参数：某链表的头的地址、要删除的val
返回值：操作后链表的头
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
函数功能：翻转链表(动态开辟头插法)
入口参数：某链表的头的地址
返回值：翻转操作后的链表的头
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
函数功能：翻转链表(三指针逆置法)
入口参数：某链表的头的地址
返回值：翻转操作后链表的头
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
函数功能：寻找链表的中间位置
入口参数：某链表的头的地址
返回值：中间位置的地址
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
函数功能：寻找链表的第K个节点
入口参数：某链表的头的地址，要寻找的K值
返回值：K的地址
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
函数功能：判断链表是否为回文结构
入口参数：某链表的头的地址
返回值：1或0
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
	//寻找中间节点
	PlistNode* n1 = head;
	PlistNode* n2 = head;
	while (n2 != NULL && n2->_next != NULL)
	{
		n1 = n1->_next;
		n2 = n2->_next;
		n2 = n2->_next;
	}
	n2 = head;

	//逆置后半部分链表
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

	//进行比对
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
函数功能：判断链表是否为回文结构
入口参数：某链表的头的地址
返回值：1或0
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
函数功能：将两个有序的链表在原地合并
入口参数：链表1头的地址、链表2头的地址
返回值：合并后链表的新头
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

	//处理头
	if (n1->_date >= n2->_date)
	{
		cur = n2->_next; //记录n2的下一步走向

		n3 = n2;
		n2->_next = n1;//双指针构成

		n2 = cur;//n2向前移动
	}
	else
	{
		n3 = n1;
		n1 = n1->_next;  //构成双指针
	}
	head = n3;//新头以保存

	//双指针法进行新构建
	while ((n1 != NULL) && (n2 != NULL))
	{
		if ((n2->_date >= n3->_date) && (n2->_date <= n1->_date))
		{
			cur = n2->_next;//保存n2的下一个链

			n3->_next = n2;
			n2->_next = n1;
			n3 = n3->_next;  //双指针向前移动

			n2 = cur;//n2向前移动
		}
		else{
			n3 = n1;
			n1 = n1->_next;  //双指针向前移动
		}
	}

	//排除特殊情况
	if (n2 != NULL)
	{
		n3->_next = n2;//直接尾插即可
	}
	return head;
}
/*
函数功能：将链表中重复元素删除
入口参数：链表得头
返回值：操作后得链表新头
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
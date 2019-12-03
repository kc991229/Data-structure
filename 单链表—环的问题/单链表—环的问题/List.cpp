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
函数功能：寻找两个相交链表的焦点
入口参数：链表A的头、链表B的头
返回值：NULL||相交节点的指针
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
函数功能：判断一个链表是否有环
入口参数：一个链表的头
返回值：true||false
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
函数功能：寻找链表的入环点
入口参数：一个链表的头
返回值：NULL||入环点处的指针
*/
PlistNode *detectCycle(PlistNode *head) 
{
	if (head == NULL || head->_next == NULL)
		return NULL;
	//排除特殊情况即为空或只有一个节点

	PlistNode* fast = head->_next->_next;//快指针走两步
	PlistNode* slow = head->_next;//慢指针走一步
	while (fast != slow && fast&& fast->_next)//这里的判断顺序不能乱，不然会出现bug
	{
		fast = fast->_next->_next;
		slow = slow->_next;
	}

	if (fast == NULL || fast->_next == NULL)
	{
		return NULL;
	}
	//判断当链表无环的情况

	else{
		slow = head;//令一个指针从链表的头开始
		while (slow != fast)//当相遇的时候就是环入口点
		{
			slow = slow->_next;
			fast = fast->_next;
		}
		return fast;
	}
}
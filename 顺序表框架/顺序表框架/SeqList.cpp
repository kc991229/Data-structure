#include "SeqList.h"
/*
函数功能：初始化
入口参数：结构体指针，初始容量
返回值：无
*/
void SeqListInit(SeqList* s1,size_t capacity)
{
	assert(s1);
	s1->_a = (Datetype*)malloc(capacity*sizeof(Datetype));
	s1->capacity = capacity;
	s1->size = 0;
}

/*  
函数功能：清除函数
入口参数：结构体指针
返回值：无
*/
void SeqListDestory(SeqList* s1)
{
	assert(s1);
	free(s1->_a);
	s1->capacity = 0;
	s1->size = 0;
	s1->_a = NULL;
}

/*
函数功能：判断容量是否充足
入口参数：结构体指针
返回值：无
*/
void SeqListCheck(SeqList* s1)
{
	assert(s1);
	if (s1->capacity == s1->size)
	{
		size_t newcapacity = s1->capacity == 0 ? 4 : s1->capacity * 2;
		s1->_a = (Datetype*)realloc(s1->_a, newcapacity * sizeof(Datetype));
		s1->capacity = newcapacity;
	}
}

/*
函数功能：头插法
入口参数：结构体指针，插入的数字
返回值：无
*/
void SeqListPushFront(SeqList* s1, Datetype num)
{
	assert(s1);
	SeqListCheck(s1);
	for (int i = s1->size - 1; i >= 0; i--)
	{
		s1->_a[i + 1] = s1->_a[i];
	}
	s1->_a[0] = num;
	s1->size++;
}

/*
函数功能：删除头数据
入口参数：结构体指针
返回值：无
*/
void SeqListPopFront(SeqList* s1)
{
	assert(s1);
	for (size_t i = 0; i < s1->size; i++)
	{
		s1->_a[i] = s1->_a[i + 1];
	}
	s1->size--;
}

/*
函数功能：尾插法
入口参数：结构体指针，插入的数据
返回值：无
*/
void SeqListPushBack(SeqList* s1, Datetype num)
{
	assert(s1);
	SeqListCheck(s1);
	s1->_a[s1->size++] = num;
	
}

/*
函数功能：删除尾端的数据
入口参数：结构体指针
返回值：无
*/
void SeqListPopBack(SeqList* s1)
{
	assert(s1&&s1->size>0);
	s1->size--;
}

/*
函数功能：查询函数
入口参数：结构体指针、查找的数字
返回值：该数字的下标或-1
*/
int SeqListFind(SeqList* s1, Datetype num)
{
	assert(s1);
	for (size_t i = 0; i < s1->size; i++)
	{
		if (s1->_a[i] == num)
			return i;
	}
	return -1;
}

/*
函数功能：任意位置插入函数
入口参数：结构体指针、插入坐标、插入的数字
返回值：无
*/
void SeqListInsert(SeqList* s1, size_t poss,Datetype num)
{
	assert(s1);
	SeqListCheck(s1);
	for (size_t i = s1->size - 1; i >= poss ; i--)
	{
		s1->_a[i + 1] = s1->_a[i];
	}
	s1->_a[poss] = num;
	s1->size++;
}

/*
函数功能：删除数据函数
入口参数：结构体指针、需要删除的坐标
返回值：无
*/
void SeqListErase(SeqList* s1, size_t poss)
{
	assert(s1);
	for (size_t i = poss; i < s1->size-1; i++)
	{
		s1->_a[i] = s1->_a[i + 1];
	}
	s1->size--;
}

/*
函数功能：直接删除该存储中的某个数据
入口参数：结构体指针、需要删除的数据
返回值：无
*/
void SeqListRemove(SeqList* s1, Datetype num)
{
	assert(s1);
	int poss = SeqListFind(s1, num);
	if (poss >= 0)
	{
		SeqListErase(s1, poss);
	}
}

/*
函数功能：冒泡排序现有的数据源
入口参数：结构体指针
返回值：无
*/
void SeqListBubbleSort(SeqList* s1)
{
	assert(s1);
	Datetype count = 0,num=0;
	for (size_t i = 0; i < s1->size-1; i++)
	{
		for (size_t j = 0; j < s1->size - 1 - i; j++)
		{
			if (s1->_a[j]>s1->_a[j + 1])
			{
				count = s1->_a[j];
				s1->_a[j] = s1->_a[j + 1];
				s1->_a[j + 1] = count;
				num = 1;
			}
		}
		if (num == 0)
			break;
	}
}
/*
函数功能：折半查找法寻找一个数据
入口参数：结构体指针，查找的数据
返回值：寻找值的下标或-1
*/
int  SeqListBinaryFind(SeqList* s1, Datetype num)
{
	size_t begin = 0, end = s1->size - 1;
	size_t mid = 0;
	while (begin <= end)
	{
		mid = (begin + end) / 2;
		if (s1->_a[mid] == num)
			return mid;
		if (s1->_a[mid] < num)
		{
			begin = mid + 1;
		}
		else if (s1->_a[mid]> num)
		{
			end = mid - 1;
		}
	}
	return -1;
}
/*
函数功能：打印函数
入口参数：结构体指针
返回值：无
*/
void SeqListPrint(SeqList* s1)
{
	assert(s1);
	for (size_t i = 0; i < s1->size; i++)
	{
		printf("%d\n", s1->_a[i]);
	}
	printf("\n");
}
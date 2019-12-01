#include "SeqList.h"
/*
�������ܣ���ʼ��
��ڲ������ṹ��ָ�룬��ʼ����
����ֵ����
*/
void SeqListInit(SeqList* s1,size_t capacity)
{
	assert(s1);
	s1->_a = (Datetype*)malloc(capacity*sizeof(Datetype));
	s1->capacity = capacity;
	s1->size = 0;
}

/*  
�������ܣ��������
��ڲ������ṹ��ָ��
����ֵ����
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
�������ܣ��ж������Ƿ����
��ڲ������ṹ��ָ��
����ֵ����
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
�������ܣ�ͷ�巨
��ڲ������ṹ��ָ�룬���������
����ֵ����
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
�������ܣ�ɾ��ͷ����
��ڲ������ṹ��ָ��
����ֵ����
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
�������ܣ�β�巨
��ڲ������ṹ��ָ�룬���������
����ֵ����
*/
void SeqListPushBack(SeqList* s1, Datetype num)
{
	assert(s1);
	SeqListCheck(s1);
	s1->_a[s1->size++] = num;
	
}

/*
�������ܣ�ɾ��β�˵�����
��ڲ������ṹ��ָ��
����ֵ����
*/
void SeqListPopBack(SeqList* s1)
{
	assert(s1&&s1->size>0);
	s1->size--;
}

/*
�������ܣ���ѯ����
��ڲ������ṹ��ָ�롢���ҵ�����
����ֵ�������ֵ��±��-1
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
�������ܣ�����λ�ò��뺯��
��ڲ������ṹ��ָ�롢�������ꡢ���������
����ֵ����
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
�������ܣ�ɾ�����ݺ���
��ڲ������ṹ��ָ�롢��Ҫɾ��������
����ֵ����
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
�������ܣ�ֱ��ɾ���ô洢�е�ĳ������
��ڲ������ṹ��ָ�롢��Ҫɾ��������
����ֵ����
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
�������ܣ�ð���������е�����Դ
��ڲ������ṹ��ָ��
����ֵ����
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
�������ܣ��۰���ҷ�Ѱ��һ������
��ڲ������ṹ��ָ�룬���ҵ�����
����ֵ��Ѱ��ֵ���±��-1
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
�������ܣ���ӡ����
��ڲ������ṹ��ָ��
����ֵ����
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
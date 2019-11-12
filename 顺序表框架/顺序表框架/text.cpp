#include "SeqList.h"

void text()
{
	SeqList s1;
	int count = 0;
	SeqListInit(&s1,2);
	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	SeqListPushFront(&s1, 0);
	SeqListPrint(&s1);
	SeqListPopFront(&s1);
	SeqListPrint(&s1);
	count = SeqListFind(&s1, 4);
	printf("%d\n\n", count);
	SeqListInsert(&s1, 2, 11);
	SeqListPrint(&s1);
	SeqListErase(&s1, 1);
	SeqListPrint(&s1);
	SeqListRemove(&s1, 5);
	SeqListPrint(&s1);
}
void text1()
{
	SeqList s2;
	int i = 0;
	SeqListInit(&s2,2);
	SeqListPushBack(&s2, 5);
	SeqListPushBack(&s2, 6);
	SeqListPushBack(&s2, 15);
	SeqListPushBack(&s2, 2);
	SeqListPushBack(&s2, 9);
	SeqListPushBack(&s2, 115);
	SeqListPrint(&s2);
    
	SeqListBubbleSort(&s2);
	SeqListPrint(&s2);
	i=SeqListBinaryFind(&s2, 5);
	i = SeqListBinaryFind(&s2, 6);
	i = SeqListBinaryFind(&s2, 2);
	i = SeqListBinaryFind(&s2, 15);
	i = SeqListBinaryFind(&s2, 9);
	i = SeqListBinaryFind(&s2, 115);

	printf("%d", i);
}
int main()
{
	//text();
	text1();
	return 0;
}
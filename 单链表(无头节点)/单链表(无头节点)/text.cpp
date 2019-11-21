#include "List.h"

void text1()
{
	PlistNode* head = NULL;
	PlistNode* cur = NULL;
	PushBack(&head, 1);
	PushBack(&head, 2);
	PushBack(&head, 3);
	PushBack(&head, 4);
	PushBack(&head, 5);
	Print(head);
	PopBack(&head);
	Print(head);
	PushFront(&head, 0);
	Print(head);
	cur = ListFind(head, 4);
	Print(cur);
	ListInsertAfter(&cur, 100);
	Print(head);
	SListEraseAfter(&cur);
	Print(head);
}
void text2()
{
	PlistNode* head1 = NULL;
	PushFront(&head1, 0);
	PushFront(&head1, 1);
	PushFront(&head1, 2);
	Print(head1);
	PopFront(&head1);
	Print(head1);
	PopFront(&head1);
	Print(head1);
	PopFront(&head1);
	Print(head1);

}
void text3()
{
	PlistNode* head = NULL;
	PlistNode* cur = NULL;
	int num = 0;
	PushBack(&head, 1);
	PushBack(&head, 2);
	PushBack(&head, 3);
	PushBack(&head, 4);
	PushBack(&head, 3);
	PushBack(&head, 2);
	PushBack(&head, 1);
	//Print(head);
	//cur = removeElements(&head, 1);
	//Print(cur);
	//cur = reverseList1(&head);
	//Print(cur);
	//cur = middleNode(&head);
	//Print(cur);
	//cur  = FindKNode(&head, 4);
	//Print(cur);
	num = ChkPalindrome1(head);
	printf("%d", num);
}
int main()
{
	//text1();
	//text2();
	text3();
	return 0;
}
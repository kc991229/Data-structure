#include "List.h"

void text1()
{
	ListNode* head = CreateHead();
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	PushBack(head, 5);
	ListPrint(head);
	PopBack(head);
	ListPrint(head);
	EraseList(&head);
	ListPrint(head);
}
void text2()
{
	ListNode* head = CreateHead();
	PushFront(head, 1);
	PushFront(head, 2);
	PushFront(head, 3);
	PushFront(head, 4);
	ListPrint(head);
	PopFront(head);
	ListPrint(head);

	EraseList(&head);
	ListPrint(head);

}
void text3()
{
	ListNode* head = CreateHead();
	ListNode* cur = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	ListPrint(head);
	cur=ListFind(head, 2);
	ListPrint(cur);

}
void text4()
{
	ListNode* head = CreateHead();
	ListNode* cur = NULL;
	PushBack(head, 1);
	PushBack(head, 2);
	PushBack(head, 3);
	PushBack(head, 4);
	ListPrint(head);
	cur = ListFind(head,2);
	ListInsert(cur, 6);
	ListPrint(head);
	cur = ListFind(head, 6);
	ListErase(cur);
	ListPrint(head);
}
int main()
{
	text4();
	return 0;
}
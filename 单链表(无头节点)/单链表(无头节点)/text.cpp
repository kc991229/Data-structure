#include "List.h"

void text1()
{
	PlistNode* head = NULL;
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
int main()
{
	text1();
	text2();
	return 0;
}
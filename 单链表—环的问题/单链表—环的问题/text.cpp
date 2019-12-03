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
}


int main()
{
	text1();
}
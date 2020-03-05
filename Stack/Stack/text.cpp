#include "Stack.h"

void text()
{
	Stack stack;
	StackInit(&stack);
	StackPush(&stack, 1);
	StackPush(&stack, 2);
	StackPush(&stack, 3);
	StackPush(&stack, 4);
	StackPush(&stack, 5);
	while (StackEmpty(&stack) == 0)
	{
		printf("%-4d", StackTop(&stack));
		StackPop(&stack);
	}
}
int main()
{
	text();
	return 0;
}
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int Datetype;
typedef struct Stack
{
	Datetype* _a;
	size_t top;
	size_t capacity;
}Stack;

void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
void StackPush(Stack* pst, Datetype Date);
void StackPop(Stack* pst);
Datetype StackTop(Stack* pst);
size_t StackSize(Stack* pst);
int StackEmpty(Stack* pst);

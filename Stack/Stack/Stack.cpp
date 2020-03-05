#include "Stack.h"

/*
函数功能：栈的初始化
*/
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
/*
函数功能：栈的销毁
*/
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
/*
函数功能：入栈
*/
void StackPush(Stack* pst,Datetype Date)
{
	assert(pst);
	if (pst->top == pst->capacity)
	{
		Datetype newcapacity = pst->capacity == 0 ? 4 : pst->capacity* 2;
		pst->_a = (Datetype*)realloc(pst->_a, newcapacity);
	}
	pst->_a[pst->top] = Date;
	pst->top++;
}
/*
函数功能：出栈
*/
void StackPop(Stack* pst)
{
	assert(pst&&pst->top > 0);
	pst->top--;
}
/*
函数功能：获取栈的顶端数据
*/
Datetype StackTop(Stack* pst)
{
	assert(pst);
	return pst->_a[pst->top - 1];
}
/*
函数功能：获取目前的总数据量
*/
size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
/*
函数功能：判断栈是否为空，返回1为空
*/
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}
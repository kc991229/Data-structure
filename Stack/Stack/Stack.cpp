#include "Stack.h"

/*
�������ܣ�ջ�ĳ�ʼ��
*/
void StackInit(Stack* pst)
{
	assert(pst);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
/*
�������ܣ�ջ������
*/
void StackDestroy(Stack* pst)
{
	assert(pst);
	free(pst->_a);
	pst->_a = NULL;
	pst->top = pst->capacity = 0;
}
/*
�������ܣ���ջ
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
�������ܣ���ջ
*/
void StackPop(Stack* pst)
{
	assert(pst&&pst->top > 0);
	pst->top--;
}
/*
�������ܣ���ȡջ�Ķ�������
*/
Datetype StackTop(Stack* pst)
{
	assert(pst);
	return pst->_a[pst->top - 1];
}
/*
�������ܣ���ȡĿǰ����������
*/
size_t StackSize(Stack* pst)
{
	assert(pst);
	return pst->top;
}
/*
�������ܣ��ж�ջ�Ƿ�Ϊ�գ�����1Ϊ��
*/
int StackEmpty(Stack* pst)
{
	assert(pst);
	return pst->top == 0 ? 1 : 0;
}
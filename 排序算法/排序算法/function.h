#ifndef _FUNCTION_H_
#define _FUNCTION_H_
#include <stdio.h>
#include <assert.h>

void Print(int *a, int n);
void Swap(int *a, int *b);
void InsertSort(int *a, int count);
void ShellSort(int *a, int count);
void SelectSort(int* a, int n);
void BubbleSort(int* a, int n);
int getmidIndex(int* a, int left, int right);
int quick_part(int *a, int begin, int end);
int quick_part2(int *a, int begin, int end);
int quick_part3(int *a, int begin, int end);
void quicksort(int *a, int left, int right);


#endif




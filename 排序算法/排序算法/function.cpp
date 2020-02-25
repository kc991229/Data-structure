#include "function.h"

void Print(int *a, int n)
{
	assert(a);
	for (int i = 0; i < n; i++)
	{
		printf("%-4d", a[i]);
	}
	printf("\n");
}
void Swap(int *a, int *b)
{
	int i = (*a);
	*a = (*b);
	*b = i;
}
void InsertSort(int *a, int count)
{	
	for (size_t i = 0; i<count - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > tmp)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
			a[end + 1] = tmp;
		}
	}
}
void ShellSort(int *a, int count)
{
	int gap = count;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (size_t i = 0; i<count - gap; i += gap)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > tmp)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
	}
}
void SelectSort(int* a, int n)
{
	int begin = 0, end = n - 1;
	while (begin < end)
	{
		int maxi = begin;
		int mini = begin;
		for (int i = begin; i <= end; i++)
		{
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
			if (a[i] < a[mini])
			{
				mini = i;
			}
		}
		Swap(&a[begin], &a[mini]);
		if (maxi == begin)
			maxi = mini;
		Swap(&a[end], &a[maxi]);
		begin++;
		end--;
	}
}
void BubbleSort(int* a, int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (a[j]>a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				count++;
			}
		}
		if (count == 0)
		{
			break;
		}
	}
}
void quicksort(int *a, int begin, int end)
{
	int key = begin;//以最后为key
	while (begin < end)
	{		
		while (begin < end && a[end] >= a[key])
		{
			end--;
		}
		while (begin < end && a[begin] <= a[key])
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);
	}
	Swap(&a[begin], &a[key]);
}
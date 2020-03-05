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
int getmidIndex(int* a, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
	else//a[left]<a[mid]
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left]>a[right])
			return left;
		else
			return right;
	}
}
int quick_part3(int *a, int begin, int end)
{
	int midIndex = getmidIndex(a, begin, end);
	Swap(&a[midIndex], &a[begin]);
	int key = a[begin];
	int cur = begin;
	int prev = cur - 1;
	while (cur <= end)
	{
		while (cur <= end && a[cur] >= key)
		{
			cur++;
		}
		if (cur > end)
			break;
		else
		{
			prev++;
			Swap(&a[prev], &a[cur]);
		}
	}
	return prev;
}

int quick_part2(int *a, int begin, int end)
{
	int mid = getmidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = a[begin];
	while (begin < end)
	{
		while (begin<end && a[end] >= key)
		{
			end--;
		}
		a[begin] = a[end];
		while (begin < end && a[begin] <= key)
		{
			begin++;
		}
		a[end] = a[begin];
	}
	a[begin] = key;
	return begin;
}
int quick_part(int *a, int begin, int end)
{
	int mid = getmidIndex(a, begin, end);
	Swap(&a[mid], &a[begin]);
	int key = begin;//以begin为key
	while (begin < end)  //以二者相遇为界
	{
		while (begin < end && a[end] >= a[key])  //end先走，寻找小于key的
		{
			end--;
		}
		while (begin < end && a[begin] <= a[key])//begin再走找大于key的
		{
			begin++;
		}

		Swap(&a[begin], &a[end]);  //进行交换
	}
	Swap(&a[begin], &a[key]);//当begin、end相遇，此时的位置就是key应该在的位置
	return begin;//返回该趟的下标，以便于接下来的操作
}
void quicksort(int *a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	if (right - left + 1 < 10)
	{
		InsertSort(a + left, right - left + 1);
	}
	else
	{
		int keyIndex = quick_part3(a, left, right);
		quicksort(a, left, keyIndex - 1);
		quicksort(a, keyIndex + 1, right);
	}



}

//非比较排序
void CountSort(int* a, int n)
{
	// 1、计算出统计次数的数组的大小
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}

	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int)*range);
	int num = 0;
	memset(countA, 0, sizeof(int)*range);//初始化为0
	// 1、统计数据出现的次数
	for (int j = 0; j < n; j++)
	{
		countA[a[j] - min]++;
	}

	// 2、根据次数排序，写回原数组
	for (int j = 0; j < range; j++)
	{
		while (countA[j]--)
		{
			a[num++] = j + min;
		}
	}
}
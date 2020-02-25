#include "function.h"

int main()
{
	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49 };
	BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	Print(arr, sizeof(arr)/sizeof(arr[0]));
	return 0;
}
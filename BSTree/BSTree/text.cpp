#include "BSTree.h"

int main()
{
	int a[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	BSTree<int> bst;
	for (auto e : a)
	{
		bst.Insert(e);
	}
	return 0;
}
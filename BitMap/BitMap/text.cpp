#include "BitMap.h"

void text()
{
	BitMap bitmap(10);
	bitmap.Set(1);
	bitmap.Set(2);
	bitmap.Set(3);
	bitmap.Set(4);
	bitmap.Set(5);
	std::cout << bitmap.Judge(2) << bitmap.Judge(10) << std::endl;
}
int main()
{
	text();
	return 0;
}
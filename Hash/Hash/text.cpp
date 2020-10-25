#include <stdio.h>

int main()
{
	char buff[4] = { '\n '};
	for (int i = 0; i < 4; i++)
		printf("%c", buff[i]);
	return 0;
}
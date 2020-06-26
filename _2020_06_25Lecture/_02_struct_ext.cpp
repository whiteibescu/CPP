#include <stdio.h>

struct _Point
{
	int x;
	int y;
};

void main()
{
	struct _Point pt;
	pt.x = 10;
	pt.y = 20;
	printf("[%d %d]\n", pt.x, pt.y);
}
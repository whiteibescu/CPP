#include <cstdio>
#include <iostream>

using namespace std;

void main()
{
	int i = 1;
	int sum = 0;
	while (i <= 10)
	{
		sum += i;
		i++;
	}
	cout << sum;
}
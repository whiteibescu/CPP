#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "양의 정수 입력(Input Positive Integer) : ";
	cin >> x;
		
	for (int i = 0; i < x; ++i)
		cout << " " << 3 * (i + 1);
}


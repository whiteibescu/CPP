#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main()
{
	int x;
	cout << "���� ���� �Է�(Input Positive Integer) : ";
	cin >> x;
		
	for (int i = 0; i < x; ++i)
		cout << " " << 3 * (i + 1);
}


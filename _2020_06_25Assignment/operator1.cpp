#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std;

int main(void)
{
	char str[256] = { 0 };
	int i = 0;

	cout << "소문자나 대문자 입력하세요 - > : ";
	cin >> str, sizeof(str);

	for (i = 0; i < (int)strlen(str); i++)
	
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
	
	else if (str[i] >= 'a' && str[i] <= 'z')
	
	str[i] -= 32;
	
	cout << "입력한 문자 대/소문자 변환" << endl;
	cout << str;
}
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>


void main()
{
	int num1 = 0;
	printf("정수입력: ");
	scanf("%d", &num1);

	int num2 = 0;
	printf("정수입력: ");
	scanf("%d", &num2);

	printf("%d + %d = %d\n", num1,num2,num1+num2);
}
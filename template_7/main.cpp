/*
Template�� ����ο� �����θ� ���Ϸ� �и��ϸ� 
������ �߻��Ѵ�

�׷��� 1���� ���Ͽ� ���ľ� �Ѵ�
*/

#include <iostream>
#include "DataArray.h"

using namespace std;

void usingIntArray() 
{
	const int ARR_LEN = 20;
	DataArray<int> intArr(ARR_LEN);

	for (int i = 0; i < ARR_LEN; i++)
		intArr.setData(i, i * 2);

	for (int i = 0; i < ARR_LEN; i++) {
		int value = 0;
		intArr.getData(i, value);
		cout << value << ", ";
	}
	cout << endl;
}

void usingDoubleArray()
{
	const int ARR_LEN = 20;
	DataArray<double> doubleArr(ARR_LEN);

	for (int i = 0; i < ARR_LEN; i++)
		doubleArr.setData(i, i * 2.1);

	for (int i = 0; i < ARR_LEN; i++) {
		double value = 0;
		doubleArr.getData(i, value);
		cout << value << ", ";
	}
	cout << endl;
}

void usingStringArray()
{
	const int ARR_LEN = 20;
	DataArray<string> stringArr(ARR_LEN);

	for (int i = 0; i < ARR_LEN; i++)
		stringArr.setData(i, "���ѹα�");

	for (int i = 0; i < ARR_LEN; i++) {
		string str;
		stringArr.getData(i, str);
		cout << str << ", ";
	}
	cout << endl;
}

void main()
{
	usingIntArray();
	usingDoubleArray();
	usingStringArray();
}

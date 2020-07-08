/*
deque(��, ��ť)
��������� �����͸� �߰��� �� �ִ� �����̳�
*/
#include <iostream>
#include <deque>
using namespace std;

void main()
{
	const int DATA_NUM = 6;
	deque<int> dEnded(DATA_NUM);
	for (int i = 0; i < DATA_NUM; i++)
		dEnded[i] = i * 2;
	dEnded.push_back(7);
	dEnded.push_front(8);

	for (int i = 0; i < dEnded.size(); i++)
		cout << dEnded[i] << ", ";
	cout << endl;
}
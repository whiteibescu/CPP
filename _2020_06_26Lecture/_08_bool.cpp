#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "���� �Է�(1�̸� 3���ݺ�): ";
	cin >> num;

	int cnt = 0;
	bool isRun = num == 1;
	cout << "bool�� ũ��: " << sizeof(bool) << endl;
	//while (num = 1)	// ������ ������ �� �� �ִ�
	while(isRun==true)
	{
		cout << cnt << endl;
		cnt++;
		if (cnt == 3)
			break;
	}
}


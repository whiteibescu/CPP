#include <iostream>

using namespace std;

void main()
{
	int num;
	cout << "���ڸ� �Է��ϼ��� : ";
	cin >> num;

	bool b = num > 0;
	if (b == true)
		cout << num<< "�� ����Դϴ�" << endl;
	else if(b == false)
		cout << num << "�� ����� �ƴմϴ�" << endl;

}
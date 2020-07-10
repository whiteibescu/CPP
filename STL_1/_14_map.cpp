#include <iostream>
#include <map>
using namespace std;

void main()
{
	/* string = key
	   int = value
	   key�� ����ؼ� value�� �˻��Ѵ�
	*/
	map<string, int> monthDayMap;

	string month[] = {
		"JAN", "FEB", "MAR", "APR",
		"MAY", "JUN", "JUL", "AUG",
		"SEP", "OCT", "NOV", "DEC"
	};
	int days[] = {
		31, 28, 31, 30, 31, 30, 
		31, 31, 30, 31, 30, 31
	};
	int arrLen = sizeof(month) / sizeof(month[0]);
	for (int i = 0; i < arrLen; i++)
		monthDayMap.insert(make_pair(month[i], days[i]));

	while (true) {
		cout << "�� �̸��� ���� �빮�ڷ� 3���� �Է� >> ";
		string input;
		cin >> input;

		map<string, int>::iterator it = monthDayMap.find(input);
		if (it == monthDayMap.end())
			cout << "�׷� ���� �����ϴ�" << endl;
		else
			cout << (*it).first << "�� " <<  (*it).second
				<< "�ϱ��� �ֽ��ϴ�" << endl;
		cout << endl << endl;
		getchar(); getchar();
		system("cls");
	}
}



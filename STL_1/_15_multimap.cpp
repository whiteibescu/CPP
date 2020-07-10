#include <iostream>
#include <map>
using namespace std;

// �� ������ �ο��ϰڴ�.
typedef multimap<int, string>::iterator yearMovieIt;

void main()
{
	multimap<int, string> yearMovieMap;
	pair<int, string> yearMovie[] = {
		make_pair(1998, "Ÿ��Ÿ��"),
		make_pair(2008, "������ �и���׾�"),
		make_pair(1997, "�λ��� �Ƹ��ٿ�"),
		make_pair(2003, "�õ庸��"),
		make_pair(1994, "���̿�ŷ"),
		make_pair(1999, "��Ʈ����"),
		make_pair(1994, "������Ʈ ����")
	};
	int arrLen = sizeof(yearMovie) / sizeof(yearMovie[0]);
	for (int i = 0; i < arrLen; i++)
		yearMovieMap.insert(yearMovie[i]);

	// �˻�
	while (true) {
		int input = 0;
		cout << "��ȭ �⵵�� �Է� >> ";
		cin >> input;

		pair<yearMovieIt, yearMovieIt> result =
			yearMovieMap.equal_range(input);
		if (result.first == result.second)
			cout << "�� �� ��ϵ� ���� ��ȭ�� �����ϴ�" << endl;
		else {
			// value�� ���� ���� �����ϹǷ� ��ü ���
			for (yearMovieIt it = result.first;
				it != result.second;
				it++) {
				cout << (*it).second << endl;
			}
		}
		getchar(); getchar();
		system("cls");
	}
}
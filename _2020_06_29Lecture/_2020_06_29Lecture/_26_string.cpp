// 3) string Ŭ���� ����ϱ�
// ���ο� char* �� �����Ҵ����� ���ڿ� ����

#include <iostream>
#include <string>

using namespace std;

void main()
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "�� �θ� ������";
	cout << "(��Ʈ : ù���ڴ� " << elvis[0] << ")? ";

	getline(cin, singer);
	if (singer == elvis)
		cout << "�¾ҽ��ϴ�" << endl;
	else
		cout << "Ʋ�Ƚ��ϴ�" + elvis + "�Դϴ�" << endl;
}
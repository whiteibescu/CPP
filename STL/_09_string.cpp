#include <iostream>
using namespace std;

// ���ڿ� �˻��� ġȯ
void main()
{
	string str("M red ballon matches my red hat.");
	string red("red");
	string blue("blue");

	size_t found = str.find(red);
	// ã�Ҵٸ� �ݺ��ض�
	while (found != string::npos) {
		str.replace(found, red.length(), blue);
		found = str.find(red, found + 1);
	}
	cout << str << endl;
}
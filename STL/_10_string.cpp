#include <iostream>
using namespace std;

void main()
{
	string str("Hi! How are you?");
	string punctuation("!?.,");

	// punctuation ���ڸ� ã�Ƽ� ����
	/*
	size_t found = str.find_first_of(punctuation);
	while (found != string::npos) {
		str.erase(found, 1);
		found = str.find_first_of(punctuation, found);
	}
	cout << str << endl;
	*/

	// punctuation ���ڸ� ã�Ƽ� ����
	size_t found = str.find_first_of(punctuation);
	while (found != string::npos) {
		str.insert(found, 2, str[found]);
		found = str.find_first_of(punctuation, found+3);
	}
	cout << str << endl;
}
#include <iostream>
#include <string>

using namespace std;

int main() 
{
	cout << "Input sentence! : " << endl;

	string text;

	cout << "----> ";
	getline(cin, text);
	for (int i = text.length() - 1; i >= 0; --i)
		cout << text[i];
	cout << endl;

}
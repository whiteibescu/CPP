#include<iostream>

using namespace std;

int main()
{
	int a, b;

	cout << "Input two intergers : - >";
	cin >> a;
	cin >> b;
	cout << "Bigger interger is - >";
	if (a > b)
		cout << a << endl;
	else
		cout << b << endl;

	return 0;
}
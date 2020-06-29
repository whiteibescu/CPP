#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

int main()
{
	char word[100] = { 0 };
	char maximum[100] = { 0 };

	cout << "Input 5 names and use ; to distinguish one name from the other : " << endl;


	for (int i = 1; i <= 5; ++i)
	{
		cin.getline(word, 100, ';');
		cout << "--"<< i << "-- " << word << endl;
		if (strlen(maximum) < strlen(word))
		{
			strcpy(maximum, word);
		}
	}

	cout << "Longest name is : " << maximum << endl;
}
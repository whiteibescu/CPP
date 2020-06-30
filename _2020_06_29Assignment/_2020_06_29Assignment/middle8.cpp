#include <iostream>
#include <string>

using namespace std;

int main()
{
	char text[50];

	cout << "Input text : --> ";
	cin.getline(text, 50);

	for (int i = 0; i < strlen(text); ++i)
	{
		for (int j = 0; j <= i; j++)
		{
			cout << text[j];
		}
		cout << endl;
	}
}
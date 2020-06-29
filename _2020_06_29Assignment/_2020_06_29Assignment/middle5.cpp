#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main()
{
	char word[10];
	while (1)
	{
		cout << "To exit, enter yes : ";
		cin.getline(word, 10);

		if (strcmp(word, "yes") == 0)
			break;
	}
}
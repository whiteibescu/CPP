#include <iostream>

using namespace std;

int main() {
	int i = 0;
	int cnt = 0;
	char strings[100];
	cout << "Input characters --> ";
	cin.getline(strings, 100);

	for (int i = 0; i < sizeof(strings); ++i)
	{
		if (strings[i] == 'x')
			cnt++;
	}

	cout << "number of x characters --> " << cnt << endl;

}
#include <iostream>

using namespace std;

int main()
{
	for (int i = 1; i <= 100; ++i)
	{
		cout << "\t" << i;

		if (i % 10 == 0) {
			cout << " \n";
		}		
	}
}

#include <iostream>

using namespace std;

int main() {
	double realnumber[5];
	double max = 0;
	cout << "Input 5 real numbers -- > ";

	for (int i = 0; i < 5; i++)
	{
		cin >> realnumber[i];
		if (max < realnumber[i])
			max = realnumber[i];
	}
	cout << "Biggest real number is -- > " << max << endl;

	return 0;
}
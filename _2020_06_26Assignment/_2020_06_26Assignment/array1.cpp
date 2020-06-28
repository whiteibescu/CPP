#include <iostream>

using namespace std;

void Input();
void SumAvg();
void BubbleSort();
int arr[5] = { 0 };

int main()
{
	Input();   //Input 5 intergers;
	SumAvg();		// Calculating sums and average of those intergers;
	BubbleSort();  // One way of sorting and finding max and min nums of array;
}

void Input()
{
	cout << "���� 5���� �Է����ּ��� : ";

	for (int i = 0; i < 5; ++i)
	{
		cin >> arr[i];
	}

	cout << "-------------------------- \n";
}

void SumAvg()
{

	int sum = 0;
	int average;

	for (int i = 0; i < 5; ++i)
	{
		sum += arr[i];
	}

	average = sum / 5;
	cout << "���� 5�� ���� : " << sum << endl;
	cout << "���� 5�� average : " << average << endl;
}

void BubbleSort()
{
	// Bubble sort - ������ �� ���� �ִ밪�� �ڿ������� ����
	for (int i = 4; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	cout << "�ּҰ� : " << arr[0] << endl;
	cout << "�ִ밪 : " << arr[4] << endl;
}
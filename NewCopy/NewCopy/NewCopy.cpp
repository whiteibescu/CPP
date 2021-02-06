/* ó���� 5���� int�迭������ �Ҵ��ϰ�
  ������ �ٽ� ��� +5�� �÷�������
*/
#include <iostream>

#define ALLOC_SIZE	5

using namespace std;

void copyArray(int dest[], int src[], int len)
{
	for (int i = 0; i < len; i++)
		dest[i] = src[i];
}

void main()
{
	int allocSize = ALLOC_SIZE;		// ���� �Ҵ� ũ��
	int* arr = NULL;
	arr = new int[allocSize];	// �����迭
	int cnt = 0;	// �Է� ����

	while (1)
	{
		cout << "���� �Է�: ";
		int num = 0;
		cin >> num;
		arr[cnt] = num;
		cnt++;
		// ���尳���� �Ҵ�ũ��� �����ϸ�
		// ���� ������ ����
		// => ������ +5 ����
		if (cnt == allocSize)
		{
			cout << "Memory Full !!!" << endl;
			cout << "Add Alloc. OK?(yes/no) : ";
			string answer;
			cin >> answer;
			if (answer == "yes" || answer == "y" ||
				answer == "Y" || answer == "Yes")
			{
				// 1) ���ο� ������ +5ũ��� �Ҵ�
				allocSize += ALLOC_SIZE;
				int* tempArr = new int[allocSize];
				// 2) ������ �迭�� �������� ����
				copyArray(tempArr, arr, allocSize - ALLOC_SIZE);
				//memcpy(tempArr, arr, 
				//	sizeof(int) * (allocSize - ALLOC_SIZE));
					// 3) ���� �� �Ҵ������ ����
				delete[] arr;
				// 4) �������� �������ּҸ�
				//    ���� �����Ϳ� ����
				arr = tempArr;
			}
			else
			{
				cout << "<��� �Է� ���� ���>" << endl;
				for (int i = 0; i < cnt; i++)
					cout << arr[i] << " ";
				cout << endl;

				delete[] arr;
				break;
			}
		}
	}
}
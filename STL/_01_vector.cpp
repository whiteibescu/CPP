/* STL(Standard Template Library)
; Template�� ������� ������� 
�ڷᱸ���� �˰��� ���̺귯��
C++ ǥ��

Data Structure == Container == Collection
*/

// vector�� ���� �迭
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> dArray(6);
	for (int i = 0; i < 6; i++)
		dArray[i] = i * 2;
	dArray.push_back(7);
	dArray.push_back(8);

	for (int i = 0; i < dArray.size(); i++)
		cout << dArray[i] << ", ";
	cout << endl;
}
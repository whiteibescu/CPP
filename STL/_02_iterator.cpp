/* Container���� Ư¡�� �ٸ��Ƿ� ���� ���� �����
���̰� �ִ�.
�׷��� ����ڰ� ���̺귯���� �� �� ���� �ٸ� �������
���� �Ѵٸ� ���ŷӰ� �ȴ�.
�׷��� ������ ������� ��� Container�� ������ ��
�ֵ��� �ߴµ� �̰��� interator(�ݺ���)��� �Ѵ�

��, �̰��� Container�� �����ϴ� �ҽ��� ǥ��ȭ�� 
���������Ƿ� Container���� ������ �ʿ䰡 ��������
*/
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

	// �ݺ��� ���
	// ��ġ����(�ε���)
	// ������ �����ε��� ����ؼ� *�� �䳻��
	// dArray�� ������ġ�� ����Ŵ
	vector<int>::iterator it = dArray.begin();
	while (it != dArray.end())
		cout << *it++ << ", ";
	cout << endl;

	for (vector<int>::iterator it = dArray.begin();
		it != dArray.end(); it++)
		cout << *it << ", ";
	cout << endl;

	// �������� ����
	vector<int>::reverse_iterator rit = 
						dArray.rbegin();
	while (rit != dArray.rend())
		cout << *rit++ << ", ";
	cout << endl;
}
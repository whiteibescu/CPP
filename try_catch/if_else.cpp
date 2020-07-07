/* 
C���� ���α׷��� �����ϴٰ� ������ �߻��� ��
�Ϲ������� return������ ó���Ѵ�.
���ϴ� return���� �ƴ� ���� ��������� �޽�����
�����ְų� ���α׷��� �����Ѵ�.
*/
/* c��� ��Ÿ���� ���� ó��*/

#include <iostream>

using namespace std;

/// <summary>
/// �����⸦ �ϴ� �Լ�
/// </summary>
/// <param name="dividend">����</param>
/// <param name="divider">�и�</param>
/// <param name="result">�����</param>
/// <returns>true�� ����, false�� ����</returns>
bool divide(double dividend, double divider, 
			double& result)
{
	if (divider == 0)
		return false;
	result = dividend / divider;
	return true;
}

void main()
{
	double num1, num2, result;

	cout << "A/B�� ������ 2���� �� �Է�: ";
	cin >> num1 >> num2;

	if (divide(num1, num2, result) == true)
		cout << num1 << "/" << num2
			<< "=" << result << endl;
	else
		cout << "Invalid Value!!!" << endl;
}
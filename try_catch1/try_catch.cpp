/* 
<C++�� try~catch���� ź�� ���>
1) �����ϴ� �ڵ念����
   ���� ������ �и��ϰ� �;���
2) �ڵ� �������� ���ؼ�
3) try{} ���� �ڵ� ����
   catch{} ���� �ڵ� ����
4) try{} �������� �߻��� ���ܸ�
   catch{}���� �޾Ƽ� ó���ϵ��� �����Ǿ� �ִ�.
5) try{} �����ȿ����� �ƴϸ� ȣ��Ǵ� �Լ���������
   ��𿡼��� try{} ���������� throw�� �ϰ� �Ǹ�
   catch�� �ٷ� �̵��ϰ� �ȴ�.
   ��, ���� �����ڵ�� �������� �ʰ� �ٷ�
   catch�������� �����ϰ� �ȴ�.
*/
#include <iostream>

using namespace std;

void divide(double dividend, double divider,
			double& result)
{
	if (divider == 0)
		throw false;
	result = dividend / divider;
}

void main()
{
	double num1, num2, result;
	cout << "A/B�� ������ 2���� �� �Է�: ";
	cin >> num1 >> num2;

	try {	// �ڵ� ���� ����
		divide(num1, num2, result);
		cout << num1 << "/" << num2
			<< "=" << result << endl;
	}catch (bool exception) {
		// ���� ó�� ����
		cout << "Invalid Value!!!" << endl;
	}
}
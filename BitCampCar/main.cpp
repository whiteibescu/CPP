#include "ICar.h"
#include "HyundaiCar.h"
#include "KiaCar.h"
#include "ToyotaCar.h"
#include "BenzCar.h"
#include "CarTester.h"

void heapDeleteAll(ICar** dpICar, int len)
{
	for (int i = 0; i < len; i++)
		delete dpICar[i];
}

int maxIdx(ICar** dpICar, int len)
{
	int maxIdx = 0;
	int max = dpICar[0]->getScore();
	for (int i = 1; i < len; i++) {
		if (max < dpICar[i]->getScore()) {
			max = dpICar[i]->getScore();
			maxIdx = i;
		}
	}

	return maxIdx;
}

void main()
{
	ICar* arrICar[] = {
			new HyundaiCar("�����ڵ���"), 
			new KiaCar("����ڵ���"),
			new ToyotaCar("����Ÿ"),
			new BenzCar("�޸�������-����")};
	int arrLen = sizeof(arrICar) / sizeof(arrICar[0]);

	CarTester carTester;
	for (int i = 0; i < arrLen; i++) {
		carTester.setICar(arrICar[i]);
		carTester.testIntegration();
	}

	for (int i = 0; i < arrLen; i++) {
		cout << arrICar[i]->getCompanyName()
			<< "  ������ : " << arrICar[i]->getScore() << endl;
	}

	int selIdx = maxIdx(arrICar, arrLen);
	cout << endl;
	cout << "������ ȸ��� " << arrICar[selIdx]->getCompanyName()
		<< " �Դϴ�" << endl;
	cout << "�ְ� ������ " << arrICar[selIdx]->getScore() 
		<< " �Դϴ�" << endl;

	heapDeleteAll(arrICar, arrLen);
}
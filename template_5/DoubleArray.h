#pragma once
class DoubleArray
{
private:
	double* arr;	// ���� �迭�����ּ�
	int arrSize;	// �迭�� �Ҵ� ũ��
public:
	DoubleArray(int arrSize = 100);
	~DoubleArray();
	bool setDouble(int idx, double value);
	bool getDouble(int idx, double& value);
};


#pragma once
class IntArray
{
private:
	int* arr;	// ���� �迭�����ּ�
	int arrSize;// �迭�� �Ҵ� ũ��
public:
	IntArray(int arrSize = 100);
	~IntArray();
	bool setInt(int idx, int value);
	bool getInt(int idx, int& value);
};


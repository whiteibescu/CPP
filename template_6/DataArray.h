#pragma once

template<typename T>
class DataArray
{
private:
	T* arr;	// ���� �迭�����ּ�
	int arrSize;// �迭�� �Ҵ� ũ��
public:
	DataArray(int arrSize = 100);
	~DataArray();
	bool setData(int idx, T value);
	bool getData(int idx, T& value);
};


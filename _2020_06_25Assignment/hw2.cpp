#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int  i, num[3], kor[3], eng[3], mat[3], total[3];

    double avg[3];

    for (i = 0; i < 3; i++) {
        cout << i + 1 << "�� �л��� ����, ����, ���� ������ �Է��ϼ���: ";
        cin >> kor[i] >> eng[i] >> mat[i];

        total[i] = kor[i] + eng[i] + mat[i];
        avg[i] = total[i] / 3.0;
    }
    cout << "" << endl;
    cout << "�й�   ����   ����   ����   ����     ���\n";
    cout <<"_________________________________________________\n";
    for (i = 0; i < 3; i++) {

        cout << i + 1 << "       " << kor[i] << "     " << eng[i] << "     " << mat[i] << "     " << total[i] << "       " << avg[i] << endl;
    }

    return 0;
}


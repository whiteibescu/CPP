#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void chopJudge(int decide, int koong) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "������" << cnt << "�� ������ϴ�.\n";
        if (cnt % koong == 0) {
            cout << "��!\n";
        }
    }
    cout <<"������ ĳ����~";
}


int main()
{
    int number;
    int koong;
    void chopTree(int number);

    cout << "���� ȸ���� �Է����ּ��� : ";
    cin >>number;
    cout << "���°�� �� : ";
    cin >> koong;



    chopJudge(number, koong);

    return 0;
}
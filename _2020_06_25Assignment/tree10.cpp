#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void chopJudge(int decide, int kkong) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "������" << cnt << "�� ������ϴ�.\n";
        if (cnt % kkong == 0) {
            cout << "½!\n";
        }
    }
    cout << "������ ĳ�����ϴ�!!\n";
}


int main()
{
    int number;
    int kkong;
    void chopTree(int number);

    cout << "���� ȸ���� �Է����ּ��� : ";
    cin >> number;
    cout << "�� �ݺ� �� ȸ���� �Է����ּ��� : ";
    cin >> kkong;

    chopJudge(number, kkong);

    return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void chopJudge(int decide, int jjuk, int kkong, int jjak) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "������" << cnt << "�� ������ϴ�.\n";
        if (cnt % jjuk == 0) {
            cout << "½!\n";
        }
        if (cnt % kkong == 0) {
            cout << "��!\n";
        }
        if (cnt % jjak == 0 || cnt == 1) {
            cout << "¦!\n";
        }

    }
    cout << "������ ĳ�����ϴ�!!\n";
}


int main()
{
    int number;
    void chopTree(int number);
     
    cout <<"���� ȸ���� �Է����ּ��� : ";
    cin >> number;

    chopJudge(number, 5, 2, 3);

    return 0;
}



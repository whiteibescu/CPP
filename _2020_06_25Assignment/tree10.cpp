#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void chopJudge(int decide, int kkong) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "나무를" << cnt << "번 찍었습니다.\n";
        if (cnt % kkong == 0) {
            cout << "쩍!\n";
        }
    }
    cout << "나무를 캐었습니다!!\n";
}


int main()
{
    int number;
    int kkong;
    void chopTree(int number);

    cout << "찍을 회수를 입력해주세요 : ";
    cin >> number;
    cout << "쿵 반복 할 회수를 입력해주세요 : ";
    cin >> kkong;

    chopJudge(number, kkong);

    return 0;
}



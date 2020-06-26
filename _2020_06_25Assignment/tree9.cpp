#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;

void chopJudge(int decide, int jjuk, int kkong, int jjak) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "나무를" << cnt << "번 찍었습니다.\n";
        if (cnt % jjuk == 0) {
            cout << "쩍!\n";
        }
        if (cnt % kkong == 0) {
            cout << "쿵!\n";
        }
        if (cnt % jjak == 0 || cnt == 1) {
            cout << "짝!\n";
        }

    }
    cout << "나무를 캐었습니다!!\n";
}


int main()
{
    int number;
    void chopTree(int number);
     
    cout <<"찍을 회수를 입력해주세요 : ";
    cin >> number;

    chopJudge(number, 5, 2, 3);

    return 0;
}



#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

void chopJudge(int decide, int koong) {
    int cnt = 0;
    for (cnt = 1; cnt <= decide; ++cnt) {
        cout << "나무를" << cnt << "번 찍었습니다.\n";
        if (cnt % koong == 0) {
            cout << "쿵!\n";
        }
    }
    cout <<"나무를 캐었다~";
}


int main()
{
    int number;
    int koong;
    void chopTree(int number);

    cout << "찍을 회수를 입력해주세요 : ";
    cin >>number;
    cout << "몇번째에 쿵 : ";
    cin >> koong;



    chopJudge(number, koong);

    return 0;
}
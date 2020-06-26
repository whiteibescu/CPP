#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

int main()
{
    int number;

    void chopTree(int number);

    cout <<"찍을 회수를 입력해주세요 : " ;
    cin >> number;


    chopTree(number);
    

    return 0;
}

void chopTree(int counting) {

    int cnt = 0;
    for (cnt = 0; cnt < counting; ++cnt) {
        cout << "나무를" << cnt + 1 << "번 찍었습니다.\n";
    } 

}
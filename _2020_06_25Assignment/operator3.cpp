#include <cstdio>
#include <iostream>
using namespace std;

void main()
{
    int a, b;
    cout << "두 개의 정수형 숫자를 입력>>";
    cin >> a;
    cin >> b;
    if (a > b)
        cout << "가장 큰 수는 :" << a;
    else if (b > a)
        cout << "가장 큰 수는 :" << b;
}
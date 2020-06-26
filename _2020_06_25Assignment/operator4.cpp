#include <cstdio>
#include <iostream>

using namespace std;

void main()
{
    int a, b, c;
    cout << "세 개의 정수형 숫자를 입력>>";
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > b && a > c)
        cout << "가장 큰 수는 : " << a;
    else if (b > a && b > c)
        cout << "가장 큰 수는 : " << b;
    else
        cout << "가장 큰 수는 : "<< c;
}


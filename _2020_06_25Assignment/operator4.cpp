#include <cstdio>
#include <iostream>

using namespace std;

void main()
{
    int a, b, c;
    cout << "�� ���� ������ ���ڸ� �Է�>>";
    cin >> a;
    cin >> b;
    cin >> c;
    if (a > b && a > c)
        cout << "���� ū ���� : " << a;
    else if (b > a && b > c)
        cout << "���� ū ���� : " << b;
    else
        cout << "���� ū ���� : "<< c;
}


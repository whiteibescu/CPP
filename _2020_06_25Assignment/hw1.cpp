#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int  i, num[10], eng[10];
    int total = 0;
    double avg;

    for (i = 0; i < 10; i++) {
        cout << i + 1 << "�� �л��� ���� ������ �Է��ϼ���: ";
        cin >> eng[i];
        
        total += eng[i];
        avg = total / 10.0;
    }
    cout << "" << endl;
    cout << "�й�    ���� " << endl;
    cout << "______________" << endl;
    cout << "______________" << endl;
    for (i = 0; i < 10; i++) {

        cout << i + 1 << "          "<< eng[i] << "\n";
    }
    cout << "______________\n";
    cout << "______________\n\n";
    
    cout <<"��� :";
    cout << avg << endl;
    cout <<"���� :";
    cout << total;

    return 0;
}


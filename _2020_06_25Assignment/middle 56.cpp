#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std; 

void main() {

    int n;
    cout << "�� ��� ȸ���� �Է����ּ��� : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*" ;
        }
        cout << "\n";
    }
}
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <iostream>

using namespace std; 

void main() {

    int n;
    cout << "별 출력 회수를 입력해주세요 : ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << "*" ;
        }
        cout << "\n";
    }
}
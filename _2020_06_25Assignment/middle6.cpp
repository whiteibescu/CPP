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
        for (int j = 0; j < n-i; j++) {
            cout << "*";
        }
        cout << "\n";
    }
}

//index 0 -> * ****Enter  i = 0 j = 5  j = 5 - i
//index 1 -> * ***Enter   i = 1 j = 4  j = 4 - i
//index 2 -> * **Enter    i = 2 j = 3  j = 3 - i
//index 3 -> * *Enter     i = 3 j = 2  j = 2 - i
//index 4 -> * Enter      i = 4 j = 1  j = 1 - i
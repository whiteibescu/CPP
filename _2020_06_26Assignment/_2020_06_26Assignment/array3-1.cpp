#include <iostream>

using namespace std;

void custom_swap(char& a, char& b) {
    char tempChar = a;
    a = b;
    b = tempChar;
}

int main() {
    char str[50];

    cout << "영어 문장을 입력해주세요: ";
    fgets(str, 50, stdin);
    int len = 0;
    while (true) {
        len++;
        if (str[len] == 0)
            break;
    }

    for (int i = 0; i < len / 2; i++) {
        custom_swap(str[i], str[len - i - 1]);
    }
    cout << "역순 결과: " << str << endl;
}
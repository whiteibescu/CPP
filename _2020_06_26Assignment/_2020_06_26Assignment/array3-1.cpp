#include <iostream>

using namespace std;

void custom_swap(char& a, char& b) {
    char tempChar = a;
    a = b;
    b = tempChar;
}

int main() {
    char str[50];

    cout << "���� ������ �Է����ּ���: ";
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
    cout << "���� ���: " << str << endl;
}
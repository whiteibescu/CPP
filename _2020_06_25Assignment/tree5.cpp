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

    cout <<"���� ȸ���� �Է����ּ��� : " ;
    cin >> number;


    chopTree(number);
    

    return 0;
}

void chopTree(int counting) {

    int cnt = 0;
    for (cnt = 0; cnt < counting; ++cnt) {
        cout << "������" << cnt + 1 << "�� ������ϴ�.\n";
    } 

}
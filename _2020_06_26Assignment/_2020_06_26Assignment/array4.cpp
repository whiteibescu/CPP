#include <iostream>

using namespace std;

int main() {
    // 4. ���̰� 5�� int�� �迭 arr�� �����ϰ�
    // 1, 2, 3, 4, 5�� �ʱ�ȭ�Ѵ�.
    int arr[5] = { 1,2,3,4,5 };
    // ������ ��Ҹ� ����Ű�� ptr�� �����ϰ�
    int* ptr = arr;
    ptr += sizeof(arr) / sizeof(int) - 1; // �迭�� ���̿� ������� ������ ���� ����Ű���� �Ϲ�ȭ(ptr += 4)

    // ptr�� �����ϴ� �������� �迭�� ��Ҹ� ��� ���Ͽ� �����
    // ����Ѵ�.
    int sum = 0;
    while (ptr >= arr) {
        cout << "���� �����Ͱ� ����Ű�� ��: " << *ptr << endl;
        sum += *ptr;
        *ptr--;
        // �Ǵ� ptr--;
        // (*ptr)--; �� �Ұ�
    }
    cout << "��: " << sum << endl;
}
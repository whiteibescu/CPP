#include <iostream>

using namespace std;



int main() {
    // 5. ���̰� 6�� �迭 arr 1, 2, 3, 4, 5, 6 ���� �ʱ�ȭ�� ����
    int arr[6] = { 1, 2, 3, 4, 5, 6 };
    // �迭�� ����� ���� ������ 6, 5, 4, 3, 2, 1�� �����Ѵ�.
    int arr_length = sizeof(arr) / sizeof(int); // �迭 ���� �Ϲ�ȭ
    // �迭�� �հ� �ڸ� ����Ű�� ������ ���� 2���� �����ؼ�
    int* start = arr;
    int* end = arr + (arr_length - 1);
    // �̸� Ȱ���Ͽ� ����� ���� ������ �ٲ�� �Ѵ�.
    while (start < end) {
        int temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    // �迭 ���
    for (int i = 0; i < arr_length; i++) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
}
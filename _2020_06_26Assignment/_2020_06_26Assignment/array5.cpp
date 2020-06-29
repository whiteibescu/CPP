#include <iostream>

using namespace std;



int main() {
    // 5. 길이가 6인 배열 arr 1, 2, 3, 4, 5, 6 으로 초기화한 다음
    int arr[6] = { 1, 2, 3, 4, 5, 6 };
    // 배열에 저장된 값의 순서를 6, 5, 4, 3, 2, 1로 변경한다.
    int arr_length = sizeof(arr) / sizeof(int); // 배열 길이 일반화
    // 배열의 앞과 뒤를 가리키는 포인터 변수 2개를 선언해서
    int* start = arr;
    int* end = arr + (arr_length - 1);
    // 이를 활용하여 저장된 값의 순서를 바꿔야 한다.
    while (start < end) {
        int temp = *start;
        *start++ = *end;
        *end-- = temp;
    }
    // 배열 출력
    for (int i = 0; i < arr_length; i++) {
        cout << "arr[" << i << "]: " << arr[i] << endl;
    }
}
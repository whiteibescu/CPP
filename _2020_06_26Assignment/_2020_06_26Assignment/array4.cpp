#include <iostream>

using namespace std;

int main() {
    // 4. 길이가 5인 int형 배열 arr을 선언하고
    // 1, 2, 3, 4, 5로 초기화한다.
    int arr[5] = { 1,2,3,4,5 };
    // 마지막 요소를 가리키는 ptr을 선언하고
    int* ptr = arr;
    ptr += sizeof(arr) / sizeof(int) - 1; // 배열의 길이와 상관없이 마지막 값을 가리키도록 일반화(ptr += 4)

    // ptr을 감소하는 연산으로 배열의 요소를 모두 더하여 결과를
    // 출력한다.
    int sum = 0;
    while (ptr >= arr) {
        cout << "현재 포인터가 가리키는 값: " << *ptr << endl;
        sum += *ptr;
        *ptr--;
        // 또는 ptr--;
        // (*ptr)--; 는 불가
    }
    cout << "합: " << sum << endl;
}
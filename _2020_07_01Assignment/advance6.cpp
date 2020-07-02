//6. Stack 클래스를 만드세요

#include <iostream>
using namespace std;
class MyIntStack {
    int p[10]; // 최대 10개의 정수 저장
    int tos; // 스택의 꼭대기를 가리키는 인덱스
public:
    MyIntStack();
    bool push(int n); // 정수 n 푸시. 꽉 차 있으면 false, 아니면 true 리턴
    bool pop(int& n); // 팝하여 n에 저장. 스택이 비어 있으면 false, 아니면 true 리턴
};
MyIntStack::MyIntStack() {
    tos = -1;
}
bool MyIntStack::push(int n) {
    if (tos == 9) return false;
    else {
        ++tos;
        p[tos] = n;
        return true;
    }

}
bool MyIntStack::pop(int& n) {
    if (tos == (-1)) return false;
    else {
        n = p[tos];
        --tos;
        return true;
    }

}
int main() {
    MyIntStack a;
    for (int i = 0; i < 11; ++i) {
        if (a.push(i)) cout << i << ' ';
        else cout << endl << i + 1 << " 번째 stack full" << endl;
    }
    int n;
    for (int i = 0; i < 11; ++i) {
        if (a.pop(n))cout << n << ' ';
        else cout << endl << i + 1 << " 번째 stack empty";
    }
    cout << endl;
}


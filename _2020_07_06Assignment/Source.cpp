#include <iostream>
using namespace std;
class Add { // 더하기 클래스
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Add::setValue(int x, int y) { //값 설정
    a = x; b = y;
}
int Add::calculate() { //더하기 연산
    return a + b;
}
class Sub { // 빼기 클래스
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Sub::setValue(int x, int y) { //값 설정
    a = x; b = y;
}
int Sub::calculate() { // 빼기 연산
    return a - b;
}
class Mul { // 곱하기 클래스
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Mul::setValue(int x, int y) { //값 설정
    a = x; b = y;
}
int Mul::calculate() { // 곱하기 연산
    return a * b;
}
class Div { // 나누기 클래스
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Div::setValue(int x, int y) { //값 설정
    a = x; b = y;
}
int Div::calculate() { // 나누기 연산
    return a / b;
}
int main() {
    Add a;
    Sub s;
    Mul m;
    Div d;
    char op;
    int x, y;
    for (;;) { // 무한루프
        cout << "숫자 연산자 숫자 입력 해주세요  ";
        cin >> x >> op >> y;
        if (op == '+') { // 더하기
            a.setValue(x, y);
            cout << "연산결과 : " << a.calculate() << endl;
        }
        else if (op == '-') { // 빼기
            s.setValue(x, y);
            cout << "연산결과 : " << s.calculate() << endl;
        }
        else if (op == '*') { // 곱하기
            m.setValue(x, y);
            cout << "연산결과 : " << m.calculate() << endl;
        }
        else if (op == '/') { // 나누기
            d.setValue(x, y);
            cout << "연산결과 : " << d.calculate() << endl;
        }
        else
            cout << "입력 오류";
    }
    return 0;
}
#include <iostream>
using namespace std;
class Add { // ���ϱ� Ŭ����
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Add::setValue(int x, int y) { //�� ����
    a = x; b = y;
}
int Add::calculate() { //���ϱ� ����
    return a + b;
}
class Sub { // ���� Ŭ����
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Sub::setValue(int x, int y) { //�� ����
    a = x; b = y;
}
int Sub::calculate() { // ���� ����
    return a - b;
}
class Mul { // ���ϱ� Ŭ����
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Mul::setValue(int x, int y) { //�� ����
    a = x; b = y;
}
int Mul::calculate() { // ���ϱ� ����
    return a * b;
}
class Div { // ������ Ŭ����
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};
void Div::setValue(int x, int y) { //�� ����
    a = x; b = y;
}
int Div::calculate() { // ������ ����
    return a / b;
}
int main() {
    Add a;
    Sub s;
    Mul m;
    Div d;
    char op;
    int x, y;
    for (;;) { // ���ѷ���
        cout << "���� ������ ���� �Է� ���ּ���  ";
        cin >> x >> op >> y;
        if (op == '+') { // ���ϱ�
            a.setValue(x, y);
            cout << "������ : " << a.calculate() << endl;
        }
        else if (op == '-') { // ����
            s.setValue(x, y);
            cout << "������ : " << s.calculate() << endl;
        }
        else if (op == '*') { // ���ϱ�
            m.setValue(x, y);
            cout << "������ : " << m.calculate() << endl;
        }
        else if (op == '/') { // ������
            d.setValue(x, y);
            cout << "������ : " << d.calculate() << endl;
        }
        else
            cout << "�Է� ����";
    }
    return 0;
}
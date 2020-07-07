#include <iostream>
using namespace std;

class Calc
{
    class Add;
    class Sub;
    class Mul;
    class Div;
};

class Add { // ���ϱ� Ŭ����
    int a, b;
public:
    void setValue(int x, int y);
    virtual int calculate();
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
    virtual int calculate();
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
    virtual int calculate();
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
    virtual int calculate();
};
void Div::setValue(int x, int y) { //�� ����
    a = x; b = y;
}
int Div::calculate() { // ������ ����
    return a / b;
}
int main() {

    Calc* calc[4] = { new Add(), new Sub(), new Mul(), new Div() };
}


/*
1. CalcŬ������ 4���� ����� ������ �ֽ��ϴ�
Calc�� �ڽ��� Add, Sub, Mul, Div Ŭ������ ����ϴ�.
int a, b;
void setValue(int x, int y);	// x�� a��, y�� b�� ����
virtual int calculate() = 0;					// ������ �����ϰ� ��� ����

calculate()�Լ��� Ŭ���� ���� ������ ������� �������ϼ���

main()�Լ����� �Ʒ�ó�� ��ü�� �����ϼ���
Calc* calc[4] = {new Add(), new Sub(), new Mul(), new Div()};

�׸��� �Ʒ�ó�� ȭ���� �����ϼ���

[����ȭ��]
����� �����ϼ��� (0:Add, 1:Sub, 2:Mul, 3:Div) >>  0
=> Add ����Դϴ�
=> ���� 2���� �Է��ϼ��� >> 10 20
=> ����� 30�Դϴ�

����� �����ϼ��� (0:Add, 1:Sub, 2:Mul, 3:Div) >>
*/
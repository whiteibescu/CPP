#include <iostream>
#include <cstdlib> //atoi,rand,malloc ���� �޼ҵ尡 ���Ե� ���̺귯��
#include <ctime> //�ð��� ���õ� �޼ҵ�, ����� ���Ե� ���̺귯��
using namespace std;

class EvenRandom {
public:
    EvenRandom() {
        srand((unsigned)time(0)); //�ٸ� �������� �߻�
    }
    int next() { //rand()�Լ��� ���� ����
        return (rand() / 2) * 2; //� ������ (Ȧ���� ¦����) 2�� ���ϸ� ¦���� �ȴ�.
    }
    int nextInRange(int a, int b) {
        return (((rand() % (b - a + 1)) + a) / 2) * 2; //a�̻� b�̸� ���� ������ �̴� �˰���

    }
};

int main(void) {
    EvenRandom r; //EvenRandom Ŭ������ ��ü r
    int i;
    cout << "-- 0���� " << RAND_MAX << "������ ���� ���� 10��--" << endl; //RAND_MAX=32767 ���
    for (i = 0; i < 10; i++) {
        cout << r.next() << " ";  //10�� ���� ���� ���
    }
    cout << "\n\n";
    cout << "-- 2���� " << "10������ ���� ���� 10��--" << endl;
    for (i = 0; i < 10; i++) {
        cout << r.nextInRange(2, 10) << " ";  //���� �� 10�� ���� ���� ���
    }
    cout << endl;
    return 0;
}

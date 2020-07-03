
//3. ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
//���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class SelectableRandom {
    int sw;
public:
    SelectableRandom(int sw);
    int next();
    int nextInRange(int a, int b);
};
SelectableRandom::SelectableRandom(int sw) {
    this->sw = sw; //¦������ Ȧ������ �Ǻ��ϴ� ����
    srand((unsigned)time(0));
}
int SelectableRandom::next() {
    if (sw == 0) {
        for (;;) {
            int k = rand();
            if (k % 2 == 0) { //¦��
                return k;
                break;
            }
        }
    }
    else {
        for (;;) {
            int k = rand();
            if (k % 2 != 0) { //Ȧ��
                return k;
                break;
            }
        }
    }
}
int SelectableRandom::nextInRange(int a, int b) {
    if (sw == 0) {
        for (;;) {
            int k = rand() % (b - a + 1) + a;
            if (k % 2 == 0) { // ¦��
                return k;
                break;
            }
        }
    }
    else {
        for (;;) {
            int k = rand() % (b - a + 1) + a;
            if (k % 2 != 0) { // Ȧ��
                return k;
                break;
            }
        }
    }
}
int main() {
    cout << "¦�� 0 Ȧ�� 1 �Է� ";
    int sw;
    cin >> sw;
    SelectableRandom r(sw);
    cout << "-- 0���� " << RAND_MAX << "������ ¦�� ���� ���� 10 ��--" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = r.next(); //0���� RAND_MAX(32767) ������ ������ ¦�� ����
        cout << n << ' ';
    }
    cout << endl << endl;
    cout << "¦�� 0 Ȧ�� 1 �Է� ";
    cin >> sw;
    SelectableRandom s(sw);
    cout << endl << endl << "-- 2���� " << "9 ������ ���� Ȧ�� ���� 10 �� --" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = s.nextInRange(2, 9); //2���� 9������ ������ Ȧ�� ����
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}

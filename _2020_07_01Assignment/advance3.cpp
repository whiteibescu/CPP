
//3. 짝수, 홀수를 선택할 수 있는 생성자를 가진 SelectableRandom 클래스를 작성하고
//각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.
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
    this->sw = sw; //짝수인지 홀수인지 판별하는 변수
    srand((unsigned)time(0));
}
int SelectableRandom::next() {
    if (sw == 0) {
        for (;;) {
            int k = rand();
            if (k % 2 == 0) { //짝수
                return k;
                break;
            }
        }
    }
    else {
        for (;;) {
            int k = rand();
            if (k % 2 != 0) { //홀수
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
            if (k % 2 == 0) { // 짝수
                return k;
                break;
            }
        }
    }
    else {
        for (;;) {
            int k = rand() % (b - a + 1) + a;
            if (k % 2 != 0) { // 홀수
                return k;
                break;
            }
        }
    }
}
int main() {
    cout << "짝수 0 홀수 1 입력 ";
    int sw;
    cin >> sw;
    SelectableRandom r(sw);
    cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10 개--" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = r.next(); //0에서 RAND_MAX(32767) 사이의 랜덤한 짝수 정수
        cout << n << ' ';
    }
    cout << endl << endl;
    cout << "짝수 0 홀수 1 입력 ";
    cin >> sw;
    SelectableRandom s(sw);
    cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 홀수 정수 10 개 --" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = s.nextInRange(2, 9); //2에서 9사이의 랜덤한 홀수 정수
        cout << n << ' ';
    }
    cout << endl;
    return 0;
}

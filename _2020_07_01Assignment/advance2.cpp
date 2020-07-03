//2. 3번을 참고해서 짝수 정수만 랜덤하게 발생시키는 EvenRandom 클래스를 작성하고
//10개의 짝수를 랜덤하게 출력하는 프로그램을 완성하세요.
//0도 짝수로 처리합니다.
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class EvenRandom {
public:
    EvenRandom();
    int next();
    int nextInRange(int x, int y);
};
EvenRandom::EvenRandom() {
    srand((unsigned)time(0));
}
int EvenRandom::next() {
    int n = rand();
    if (n % 2 == 0) return n;
    else return n - 1;
}
int EvenRandom::nextInRange(int x, int y) {
    int n = rand() % (y - x + 1) + x;
    if (n % 2 == 0) return n;
    else return n - 1;
}
int main() {
    EvenRandom r;
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = r.next(); // 0에서 RAND_MAX(32767) 사이의 랜덤한 정수
        cout << n << ' ';
    }
    cout << endl << endl << "-- 2에서 " << "10 까지의 랜덤 정수 10 개 --" << endl;
    for (int i = 0; i < 10; ++i) {
        int n = r.nextInRange(2, 10); //2에서 10 사이의 랜덤한 저수
        cout << n << ' ';
    }
    cout << endl;
}
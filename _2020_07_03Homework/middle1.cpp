#include <iostream>
#include <cstdlib> //atoi,rand,malloc 등의 메소드가 포함된 라이브러리
#include <ctime> //시간과 관련된 메소드, 상수가 포함된 라이브러리
using namespace std;

class EvenRandom {
public:
    EvenRandom() {
        srand((unsigned)time(0)); //다른 랜덤수를 발생
    }
    int next() { //rand()함수는 정수 리턴
        return (rand() / 2) * 2; //어떤 정수든 (홀수든 짝수든) 2를 곱하면 짝수가 된다.
    }
    int nextInRange(int a, int b) {
        return (((rand() % (b - a + 1)) + a) / 2) * 2; //a이상 b미만 랜덤 정수를 뽑는 알고리즘

    }
};

int main(void) {
    EvenRandom r; //EvenRandom 클래스의 객체 r
    int i;
    cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl; //RAND_MAX=32767 상수
    for (i = 0; i < 10; i++) {
        cout << r.next() << " ";  //10개 랜덤 정수 출력
    }
    cout << "\n\n";
    cout << "-- 2에서 " << "10까지의 랜덤 정수 10개--" << endl;
    for (i = 0; i < 10; i++) {
        cout << r.nextInRange(2, 10) << " ";  //범위 내 10개 랜덤 정수 출력
    }
    cout << endl;
    return 0;
}

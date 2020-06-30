#include <iostream>
#include <cstdlib>
#include <ctime> 

using namespace std;

class Random {
private:
	int n;
public:
	Random();
	int next();
	int nextInRange(int a, int b);
};

Random::Random(){ // 랜덤함수 생성
	srand((unsigned)time(0));
}

int Random::next() { // 랜덤 리턴
	return rand();
}

int Random::nextInRange(int a, int b) {
	return rand() % (b - a + 1) + a; //a~b까지 랜덤
}

int main() {
	Random r;
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next(); // 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "4 까지의 랜덤 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4); // 2에서 4 사이의 랜덤한 정수
		cout << n << ' ';
	}
	cout << endl;
}

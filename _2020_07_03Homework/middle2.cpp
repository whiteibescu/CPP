/*
2. EvenRandom 클래스를 상속해 짝수, 홀수를 선택할 수 있는 생성자를 가진
   생성자를 가진 SelectableRandom 클래스를 작성하고
   next()를 재정의하여
   각각 짝수 10개, 홀수 10개를 랜덤하게 발생시키는 프로그램을 작성하세요.
*/


#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class SelectableRandom {
	string s;
public:
	SelectableRandom(string s) { this->s = s; srand((unsigned)time(0)); }
	int next();
	int nextInRange(int a, int b);
	string getstr() { return s; }
};
int SelectableRandom::next() {
	int n = rand();
	if (s == "홀수")
		while (n % 2 == 0) n = rand();
	else if (s == "짝수")
		while (n % 2 == 1) n = rand();
	return n;
}
int SelectableRandom::nextInRange(int a, int b) {
	int n;
	n = a + (rand() % (b - a + 1));
	if (s == "홀수")
		while (n % 2 == 0) n = a + (rand() % (b - a + 1));
	else if (s == "짝수")
		while (n % 2 == 1) n = a + (rand() % (b - a + 1));
	return n;
}

int main() {
	SelectableRandom r("짝수");
	SelectableRandom rr("홀수");

	cout << "-- 0에서 " << RAND_MAX << "까지의 " << r.getstr() << " 랜덤 정수 10 개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2에서 " << "9 까지의 랜덤 " << rr.getstr() << " 정수 10 개 --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = rr.nextInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
}
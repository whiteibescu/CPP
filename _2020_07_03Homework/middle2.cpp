/*
2. EvenRandom Ŭ������ ����� ¦��, Ȧ���� ������ �� �ִ� �����ڸ� ����
   �����ڸ� ���� SelectableRandom Ŭ������ �ۼ��ϰ�
   next()�� �������Ͽ�
   ���� ¦�� 10��, Ȧ�� 10���� �����ϰ� �߻���Ű�� ���α׷��� �ۼ��ϼ���.
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
	if (s == "Ȧ��")
		while (n % 2 == 0) n = rand();
	else if (s == "¦��")
		while (n % 2 == 1) n = rand();
	return n;
}
int SelectableRandom::nextInRange(int a, int b) {
	int n;
	n = a + (rand() % (b - a + 1));
	if (s == "Ȧ��")
		while (n % 2 == 0) n = a + (rand() % (b - a + 1));
	else if (s == "¦��")
		while (n % 2 == 1) n = a + (rand() % (b - a + 1));
	return n;
}

int main() {
	SelectableRandom r("¦��");
	SelectableRandom rr("Ȧ��");

	cout << "-- 0���� " << RAND_MAX << "������ " << r.getstr() << " ���� ���� 10 ��--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "-- 2���� " << "9 ������ ���� " << rr.getstr() << " ���� 10 �� --" << endl;
	for (int i = 0; i < 10; i++) {
		int n = rr.nextInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
}
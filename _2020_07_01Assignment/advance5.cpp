
5. Accumulator Ŭ������ �����ϼ���.


#include <iostream>
using namespace std;

class Accumulator {
	int value;
public:
	Accumulator(int value);
	Accumulator& add(int n);
	int get();
};
;
int main() {
	Accumulator acc(10);
	acc.add(5).add(6).add(7); // acc�� value ����� 28�� �ȴ�.
	cout << acc.get() << endl; // 28 ���
}

6. Stack Ŭ������ ���弼��

#include <iostream>
using namespace std;

class MyIntStack {
	int p[10];
	int tos; // ������ ����⸦ ����Ű�� �ε���
public:
	MyIntStack();
	bool push(int n); // ���� n Ǫ��. �� �� ������ false, �ƴϸ� true ����
	bool pop(int& n); // ���Ͽ� n�� ����.������ ��� ������ false, �ƴϸ� true ����
};


int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) { // 11���� Ǫ���Ѵ�.
		if (a.push(i)) cout << i << ' '; // Ǫ�õ� �� ����
		else cout << endl << i + 1 << " ��° stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) { // 11���� ���Ѵ�.
		if (a.pop(n)) cout << n << ' '; // �� �� �� ���
		else cout << endl << i + 1 << " ��° stack empty";
	}
	cout << endl;
}


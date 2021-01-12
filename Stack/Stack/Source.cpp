#include <iostream>
#include <stack>

using namespace std;

int main() {

	// ���� ����
	stack<int> s;


	// push
	s.push(3);
	s.push(2);
	s.push(1);


	// top
	cout << "top element: " << s.top() << '\n';


	// pop
	s.pop(); // 1�� ����
	s.pop(); // 2�� ����


	// size
	cout << "stack size: " << s.size() << '\n';


	// empty
	cout << "Is it empty?: " << (s.empty() ? "Yes" : "No") << '\n';

	return 0;

}
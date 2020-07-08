/*
Adapter Container
스택 / 큐
; vector/list로 재구성한 Container
*/
#include <iostream>
#include <stack>
using namespace std;

void main()
{
	stack<int> iStack;

	iStack.push(10);
	iStack.push(20);
	iStack.push(30);

	while (!iStack.empty())
	{
		cout << iStack.top() << ", ";
		iStack.pop();
	}
}
/*
Adapter Container
���� / ť
; vector/list�� �籸���� Container
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
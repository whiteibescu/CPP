/* STL(Standard Template Library)
; Template을 기반으로 만들어진 
자료구조와 알고리즘 라이브러리
C++ 표준

Data Structure == Container == Collection
*/

// vector은 동적 배열
#include <iostream>
#include <vector>
using namespace std;

void main()
{
	vector<int> dArray(6);
	for (int i = 0; i < 6; i++)
		dArray[i] = i * 2;
	dArray.push_back(7);
	dArray.push_back(8);

	for (int i = 0; i < dArray.size(); i++)
		cout << dArray[i] << ", ";
	cout << endl;
}
//1. main()의 실행 결과가 다음과 같도록 Tower클래스를 작성하세요
//
//높이는 1미터
//높이는 100미터

#include <iostream>

using namespace std;

class Tower {
private:
	int meter;

public:
	Tower()
	{
		meter = 5;
	}

	Tower(int m)
	{
		meter = m;
	}
	int getHeight()
	{
		return meter;
	}
};


void main()
{
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
}
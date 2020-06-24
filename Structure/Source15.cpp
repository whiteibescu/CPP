#include<iostream>

using namespace std;

class Point
{
	private:
		int x;
		int y;

public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);

};
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

class Point
{
private:
	char* Name;
	int x;
	int y;

public:
	Point(char* _Name, int _x, int _y);
	Point(const Point& pt);
	~Point();

public:
	void SetPoint(int _x, int _y);
	void AddPoint(Point& pt);
	void SubPoint(Point& pt);
	void MovePoint(int addX, int addY);
	void ShowPoint();
}; 


Point::Point(const Point& apt)
{
	Name = new char[strlen(apt.Name) + 1];
	memset(Name, 0, strlen(apt.Name) + 1);
	strncpy(Name, apt.Name, strlen(apt.Name));
	x = apt.x;
	y = apt.y;
	cout << "복사생성자호출" << endl;
}
Point::~Point()
{
	delete [] Name;
	cout << "소멸자 호출" << endl;
}

void Point::AddPoint(Point& pt)
{
	x += pt.x;
	y += pt.y;
}

void Point::SubPoint(Point& pt)
{
	x -= pt.x;
	y -= pt.y;
}

void Point::MovePoint(int addX, int addY)
{
	x += addX;
	y += addY;
}

void Point::ShowPoint()
{
	cout << "x, y : [ " << x << ", " << y << "]" << endl;
}

void main()
{
	Point pt("원점", 100, 100);
	Point pt1 = pt;
	pt1.ShowPoint();
}
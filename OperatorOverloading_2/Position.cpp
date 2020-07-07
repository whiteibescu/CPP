#include "Position.h"
#include <iostream>
using namespace std;

Position::Position(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Position::showPosition()
{
	cout << "[" << this->x << ", "
		<< this->y << "]" << endl;
}
Position& Position::operator++()
{
	++(this->x);
	++(this->y);

	// �����ڰ� �ִ� �������� ������ �Ѽ��ϴ�
	// �ڵ��� �����ؾ� �Ѵ�
	//this->x -= 100;
	//this->y *= 92;

	// self ��ü
	return *this;
}

Position Position::operator++(int)
{
	Position temp = *this;
	++(this->x);
	++(this->y);
	return temp;
}
Position Position::operator+(Position pos)
{
	Position temp;
	temp.x = this->x + pos.x;
	temp.y = this->y + pos.y;
	return temp;
}
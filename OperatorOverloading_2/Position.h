#pragma once
class Position
{
private:
	int x, y;
public:
	Position(int x = 0, int y = 0);
public:
	void showPosition();
	Position& operator++();	    // ��������������
	Position operator++(int);	// ��������������
	Position operator+(Position pos);
};


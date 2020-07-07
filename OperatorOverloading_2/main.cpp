

#include "Position.h"

void main()
{
	Position pos(10, 100);
	Position pos1(20, 200);
	//pos.operator+(pos1);
	Position pos2 = pos + pos1;
	pos2.showPosition();
}
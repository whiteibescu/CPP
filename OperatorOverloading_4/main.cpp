

#include "Position.h"

void main()
{
	Position pos(10, 100);
	//5.operator+(pos);		//불가능
	//operator+(5, pos);	// 전역함수 호출
	Position pos1 = 5 + pos;
	pos1.showPosition();
}
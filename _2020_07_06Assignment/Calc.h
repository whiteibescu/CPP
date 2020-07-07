#pragma once

class Calc
{
protected:
	int a;
	int b;
public:
	void setValue(int x, int y);
	virtual int calculate() = 0;
};


#pragma once
#include "Police.h"
#include "Gun.h"

class ForcePolice : public Police
{
private:
	int handCuffs = 3;
	Gun gun;	// ���԰���

public:
	void snap();
	void fireGun();
};


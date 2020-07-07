#include "Korea.h"
#include "China.h"
#include "Corona.h"
#include "America.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>

using namespace std;

void main()
{
	Corona* arrcorona[] = { new China(), new Korea(), new America()};
	arrcorona[0]->maskQuantity();
	arrcorona[1]->maskQuantity();
	arrcorona[2]->maskQuantity();

	
}
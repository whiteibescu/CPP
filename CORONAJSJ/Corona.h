#pragma once
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <combaseapi.h>

using namespace std;

interface Corona						// 인터페이스 코로나
{
	double Population;					// 인구(실수형)
	double Infected;   					// 감염자(실수형)
	string CountryName;					// 국가명(문자열)
	
	virtual void infectee() = 0;		// 랜덤 감염자 생산 함수
	virtual int getInfected_NUM() = 0;	// 랜덤 감염자 생산 함수 -> 클래스 Infected 변수에 넘겨주는 역할을 하는 함수
};



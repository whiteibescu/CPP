#pragma once
#include "Corona.h"

#define C_BASIC_INFECTEE_NUM 100
#define C_COUNTRY_INFECTEE_NUM 100

class China : public Corona
{

public:
    China();                       // 생성자역할 : 난수생성, Corona에서 받아온 클래스 변수에 초기값 부여(인구, 감염자, 마스크, 국가이름)
    virtual void infectee();                
    virtual int getInfected_NUM(); // 랜덤 감염자 생산 함수 -> 클래스 Infected 변수에 넘겨주는 역할을 하는 함수
};



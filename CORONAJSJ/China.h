#pragma once
#include "Corona.h"

#define C_BASIC_INFECTEE_NUM 100
#define C_COUNTRY_INFECTEE_NUM 100

class China : public Corona
{

public:
    China();                       // �����ڿ��� : ��������, Corona���� �޾ƿ� Ŭ���� ������ �ʱⰪ �ο�(�α�, ������, ����ũ, �����̸�)
    virtual void infectee();                
    virtual int getInfected_NUM(); // ���� ������ ���� �Լ� -> Ŭ���� Infected ������ �Ѱ��ִ� ������ �ϴ� �Լ�
};



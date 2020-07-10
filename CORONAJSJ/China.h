#pragma once
#include "Corona.h"

#define C_BASIC_MASK_NUM 10
#define C_COUNTRY_MASK_NUM 100
#define C_BASIC_INFECTEE_NUM 200
#define C_COUNTRY_INFECTEE_NUM 100

class China : public Corona
{

public:
    China();                                 // �����ڿ��� : ��������, Corona���� �޾ƿ� Ŭ���� ������ �ʱⰪ �ο�(�α�, ������, ����ũ, �����̸�)
    virtual void maskQuantity();            // ���� ����ũ ���� �Լ�
    virtual void infectee();                // ���� ������ ���� �Լ�
    virtual int getMask_NUM();              // ���� ����ũ ���� �Լ� -> Ŭ���� Mask ������ �Ѱ��ִ� ������ �ϴ� �Լ�
    virtual int getInfected_NUM();          // ���� ������ ���� �Լ� -> Ŭ���� Infected ������ �Ѱ��ִ� ������ �ϴ� �Լ�
};



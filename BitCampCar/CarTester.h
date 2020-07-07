#pragma once

#include <iostream>
#include "ICar.h"

#define TEST_INTEGRATION_CNT	1
#define TEST_DRIVING_CNT		3
#define TEST_ACCELING_CNT		3
#define TEST_BRAKING_CNT		3
#define TEST_REPETITION_CNT		3

using namespace std;

class CarTester
{
private:
	// CarTester�� �������(���԰���)
	// Dependency Injection(������ ����)
	ICar* iCar = NULL;

public:
	CarTester(ICar* pICar = NULL);

private:
	void testDriving();
	void testMaxAcceling();
	void testMaxBraking();
	void testRepetition();

public:
	void testIntegration();
	void setICar(ICar* pICar);
};


#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
	unsigned char val4 = 0xFE;
	unsigned char val5 = 0;
	unsigned char val6 = 0;

	cout << "val4(2진수): " << bitset<8>(val4) << endl;

	val6 = val4 >> 4;
	cout << "val4 오른쪽으로 4비트 시프트 결과 == 0x0E" << endl;
	cout << "val6(2진수): " << bitset<8>(val6) << endl;

	cout << "val4(2진수): " << bitset<8>(val4) << endl;
	cout << "  15(2진수): " << bitset<8>(15) << endl;
	val5 = val4 & 15;
	cout << "val5(2진수): " << bitset<8>(val5) << endl;

	printf("0x%02X = 0x%02X + 0x%02X\n", val4, val4 >> 4, val4 & 15);
}
#include <mmsystem.h>
#include <iostream>
#include <windows.h>
#include <conio.h>

#pragma comment(lib, "winmm.lib")
#define music "abc.wav"
using namespace std;

int main()
{
	PlaySound(TEXT(music), NULL, SND_ASYNC);
	_getch();

}
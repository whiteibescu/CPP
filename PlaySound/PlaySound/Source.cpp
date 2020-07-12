#include <mmsystem.h>
#include <iostream>
#include <windows.h>

#pragma comment(lib, "winmm.lib")
#define music "123.WAV"
using namespace std;

int main()
{
	PlaySound(TEXT(music), NULL, SND_ASYNC);

}
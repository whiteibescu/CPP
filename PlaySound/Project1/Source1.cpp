#include <windows.h>
#include <gdiplus.h>
#include <stdio.h>

using namespace Gdiplus;

int main()
{
	char keyInput[10] = "";
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken = NULL;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	Graphics* pGraphics = new Graphics(GetDC(GetConsoleWindow()));
	Image* pImage = pGraphics ? new Image(L"C:\\User\\white\\source\\repos\\whiteibescu\\CPP\\PlaySound\\pic.bmp") : NULL;


	if (pImage)
	{
		pGraphics->DrawImage(pImage, 10, 10);
	}
	else
	{
		printf("Error\n");
	}

	fgets(keyInput, 10, stdin);

	delete pImage;
	delete pGraphics;
	GdiplusShutdown(gdiplusToken);
	return 0;
}
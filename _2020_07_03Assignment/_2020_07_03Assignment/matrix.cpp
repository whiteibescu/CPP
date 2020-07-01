#include "Turboc.h"
#pragma warning (disable:4996)

#define MAX 1024
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

struct Signal
{
	BOOL exist;				// 신호의 존재 여부
	char ch;				// 출력할 문자
	int x, y;				// 현재 좌표
	int distance;			// 이동할 거리1
	int nFrame;				// 속도
	int nStay;				// 속도에 대한 카운트
};

struct Signal S[MAX];

void main()
{	
	setcursortype(NOCURSOR);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	int i;
	int ch;
	int freq = 15;
	int frame = 200;

	clrscr();
	gotoxy(0, 23);
	printf("매트릭스 흉내내기. 상하:속도 증감, 좌우:빈도 증감, ESC:종료");
	randomize();
	for (;;) {
		gotoxy(60, 23);
		printf("속도:%d, 빈도:%d    ", frame, freq);

		// 키 입력 처리
		if (kbhit()) {
			ch = getch();
			if (ch == 0xE0) {
				ch = getch();
				switch (ch) {
				case UP:
					frame = min(frame + 10, 1000);
					break;
				case DOWN:
					frame = max(frame - 10, 10);
					break;
				case RIGHT:
					freq = max(freq - 1, 1);
					break;
				case LEFT:
					freq = min(freq + 1, 30);
					break;
				}
			}
			else {
				if (ch == ESC) {
					return;
				}
			}
		}

		// 새로운 신호 생성
		int count = 0;
		if (random(freq) == 0) {
			int x = random(80);
			int this_distance = random(14) + 9;
			for (i = 0; i < MAX; i++) {
				if (S[i].exist == FALSE) {
					S[i].exist = TRUE;
					S[i].ch = random('Z' - 'A' + 1) + 'A';
					// S[i].x = random(80);
					S[i].x = x;
					S[i].y = 0;
					// S[i].distance = random(14) + 9;
					S[i].distance = this_distance;
					// S[i].nFrame = S[i].nStay = random(15) + 5;
					S[i].nFrame = S[i].nStay = count + 5;
					count++;
				}
				if (count == 15)
					break;
			}
		}

		// 주기가 다 된 신호 이동 및 제거 처리
		for (i = 0; i < MAX; i++) {
			if (S[i].exist == FALSE)
				continue;
			if (--S[i].nStay == 0) {
				S[i].nStay = S[i].nFrame;
				gotoxy(S[i].x, S[i].y); putch(' ');
				if (++S[i].y < S[i].distance) {
					gotoxy(S[i].x, S[i].y); putch(S[i].ch);
				}
				else {
					S[i].exist = FALSE;
				}
			}
		}

		delay(500 / frame);
	}
}

/*
// 주기가 다 된 신호 이동 및 제거 처리
for (i=0;i<MAX;i++) {
	if (S[i].exist == FALSE)
		continue;
	gotoxy(S[i].x,S[i].y);puts("       ");
	if (--S[i].nStay == 0) {
		S[i].nStay=S[i].nFrame;
		if (++S[i].y >= S[i].distance) {
			S[i].exist=FALSE;
		}
	}
	if (S[i].exist) {
		gotoxy(S[i].x,S[i].y);
		printf("%c-%d:%d ",S[i].ch,S[i].nFrame,S[i].nStay);
	}
}

delay(100);
*/


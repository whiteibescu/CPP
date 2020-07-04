#include "Turboc.h"
#pragma warning (disable:4996)

#define MAX 1024
#define LEFT 75 
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define COLOR 49

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
	setcursortype(NOCURSOR);	//커서 없애기
	int i;
	int ch;
	int freq = 15;
	int frame = 200;

	clrscr();

	randomize();			// srand((unsigned)time(NULL)); 
	for (;;) {   

		gotoxy(0, 25);
		printf("----------------------------------------------------------------------------------\n");
		printf("\\    /\\                            \\    /\\                            \\    /\\\n");      
		printf(" )  ( \')                            )  ( \')                            )  ( \')\n");
		printf("(  /  )                            (  /  )                            (  /  )\n");
		printf(" \\(__)|                             \\(__)|                             \\(__)|");
		gotoxy(60, 23);-
		printf("속도:%d, 빈도:%d    ", frame, freq);
		gotoxy(0, 23);
		printf("1번: 색상 변경 상하:속도 증감, 좌우:빈도 증감, ESC:종료");

		// 키 입력 처리
		if (kbhit()) { //특수키는 2바이트
			ch = getch();
			if (ch == COLOR)
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (rand() % 14) + 1); //콘솔창 폰트 색상 초록색
			if (ch == 0xE0) { //특수키
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
					clrscr();

					printf("|\\_/|\n");
					printf("|q p|   /}\n");
					printf("( 0 )\"\"\"\\\n");
					printf("|\"^\"`    |\n");
					printf("||_/=\\\\__|");

					break;
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
					S[i].nFrame = S[i].nStay = count  + 5;
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


#include "Turboc.h"
#pragma warning (disable:4996)
//��� ó�� switch���� ���
#define MAX 1024
#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27 //�ƽ�Ű�ڵ� ��
#define GREEN 2 

struct Signal //��ȣ�� ���� ����ü
{
    BOOL exist;            // ��ȣ�� ���� ����
    char ch;            // ����� ����
    int x, y;            // ���� ��ǥ
    int distance;         // �̵��� �Ÿ�
    int nFrame;            // �ӵ�
    int nStay;            // �ӵ��� ���� ī��Ʈ
};
Signal S[MAX];

void main()
{
    int i;
    int ch;
    int freq = 80;
    int frame = 500;

    clrscr();  //ȭ�� û��
    gotoxy(0, 23);
    printf("��Ʈ���� �䳻����. ����:�ӵ� ����, �¿�:�� ����, ESC:����");
    randomize();
    for (;;) {
        gotoxy(60, 23); //�ܼ� ��ǥ�迡 '��ġ'
        printf("�ӵ�:%d, ��:%d    ", frame, freq);

        // Ű �Է� ó��
        if (kbhit()) { //Ű �Է¿���, �Է��� ������ 1, ������ 0//
            ch = getch(); //char  �� �Է¹���.
            if (ch == 0xE0) {   //space
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

        // ���ο� ��ȣ ����
        if (random(freq) == 0) {
            for (i = 0; i < MAX; i++) {
                if (S[i].exist == FALSE) {
                    S[i].exist = TRUE;
                    S[i].ch = random('Z' - 'A' + 1) + 'A'; //���ĺ� �ƽ�Ű �ڵ� �� ���� A~Z ������ ���ؼ� �������� ���
                    S[i].x = random(100);
                    S[i].y = 0;
                    S[i].distance = random(14) + 9; // �������� ����
                    S[i].nFrame = S[i].nStay = random(15) + 5; //����ǥ���� �ӹ����� �ð� 
                    break;
                }
            }
        }

        // �ֱⰡ �� �� ��ȣ �̵� �� ���� ó��
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

        delay(1000 / frame);
    }
}

/*
// �ֱⰡ �� �� ��ȣ �̵� �� ���� ó��
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
\
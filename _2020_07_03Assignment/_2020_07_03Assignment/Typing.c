#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<windows.h> 

#define MAX_NUM 100    //��Ʈ���� �ְ� �� ���� 

typedef enum { OFF, ON } ON_OFF; //ON_OFF ����ġ ������ ���� 
struct signal {            //��Ʈ���� ��ȣ�ٿ� ���� ����ü 
    ON_OFF signal_on;    //on���� off���� �˷��� 
    char ch;            //ǥ���� ASCII ��ȣ 
    int x, y;            //��ǥ�� 
    int speed;            //�ӵ� 
};

struct signal S[MAX_NUM]; //��ȣ�� ������ �迭�� MAX_NUM��ŭ ����ϴ�.  
int cnt; // �ð����� ī��Ʈ 

void gotoxy(int x, int y) {    //gotoxy�Լ� 
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;    //Ŀ�� ���ֱ� 
void setcursortype(CURSOR_TYPE c) {                                    //Ŀ�� ���ֱ� 
    CONSOLE_CURSOR_INFO CurInfo;

    switch (c) {
    case NOCURSOR:
        CurInfo.dwSize = 1;
        CurInfo.bVisible = FALSE;
        break;
    case SOLIDCURSOR:
        CurInfo.dwSize = 100;
        CurInfo.bVisible = TRUE;
        break;
    case NORMALCURSOR:
        CurInfo.dwSize = 20;
        CurInfo.bVisible = TRUE;
        break;
    }
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

void reset(void); //�ʱ� �����Լ� 
void new_signal(void); //���ο� ��ȣ�� �����Լ� 
void draw(void); //ȭ�� �׸��� �Լ� 
void move(void); //��ȣ�� ��ĭ ������ �Լ� 

int main() {
    setcursortype(NOCURSOR); //Ŀ������� 
    reset();

    for (cnt = 0;; cnt++) {
        if (cnt % 10 == 0) new_signal();    //ī��Ʈ�� 10������ ��ȣ�� �ϳ� ���� 
        draw();
        move();
        Sleep(50); // 0.05�ʰ� ������(�ּ������Ӽӵ�) 
    }
}

void reset(void) {
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_NUM; i++) { //��ȣ ����ġ�� ���� off�� �ʱ�ȭ 
        S[i].signal_on = OFF;
    }
}
void new_signal(void) {
    int i, j;

    for (i = 0; i < MAX_NUM; i++) { //���ο� ��ȣ�� �ϳ� ���� 
        if (S[i].signal_on == OFF) {
            S[i].signal_on = ON;
            S[i].ch = rand() % 95 + 32; // ASCII 32������ 127���߿� �ϳ� ���� 
            S[i].x = rand() % 80;
            S[i].y = 0;
            S[i].speed = rand() % 20 + 1;
            break;
        }
    }

    for (j = 0; j < 4; j++) { //��ȣ�� ����� ��ȣ�� 4�� ���� 
        for (i = 0; i < MAX_NUM; i++) {
            if (S[i].signal_on == OFF) {
                S[i].signal_on = ON;
                S[i].ch = ' '; // move�Լ����� ch�� ' '�ΰ�� ���찳�� �˴ϴ�. 
                S[i].x = rand() % 80;
                S[i].y = 0;
                S[i].speed = 1; //����°� �������� 
                break;
            }
        }
    }
}

void draw(void) {
    int i;

    for (i = 0; i < MAX_NUM; i++) {
        if (S[i].signal_on == ON) {
            gotoxy(S[i].x, S[i].y); putchar(S[i].ch);
        }
    }
}

void move(void) {
    int i;

    for (i = 0; i < MAX_NUM; i++) {
        if (S[i].signal_on == ON && S[i].y == 23) { //�������ٿ� �����ϸ� ����ġ�� off�� ������ 
            S[i].signal_on = OFF;
        }

        if (S[i].signal_on == ON && cnt % S[i].speed == 0) {
            if (rand() % 24 == 0) S[i].ch = ' '; // 24���� 1Ȯ���� ��ȣ�� ���찳�� �ٲ� 
            if (S[i].ch != ' ') S[i].ch = rand() % 95 + 32; //��ȣ�� ' '�� ���� ��� ' '�� ��� 
            S[i].y++;
        }
    }
}

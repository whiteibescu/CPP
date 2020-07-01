#include<stdio.h> 
#include<stdlib.h>
#include<time.h>
#include<windows.h> 

#define MAX_NUM 100    //매트릭스 최고 줄 갯수 

typedef enum { OFF, ON } ON_OFF; //ON_OFF 스위치 열거형 정의 
struct signal {            //매트릭스 신호줄에 대한 구조체 
    ON_OFF signal_on;    //on인지 off인지 알려줌 
    char ch;            //표시할 ASCII 번호 
    int x, y;            //좌표값 
    int speed;            //속도 
};

struct signal S[MAX_NUM]; //신호를 저장할 배열을 MAX_NUM만큼 만듭니다.  
int cnt; // 시간값을 카운트 

void gotoxy(int x, int y) {    //gotoxy함수 
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;    //커서 없애기 
void setcursortype(CURSOR_TYPE c) {                                    //커서 없애기 
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

void reset(void); //초기 세팅함수 
void new_signal(void); //새로운 신호줄 생성함수 
void draw(void); //화면 그리는 함수 
void move(void); //신호를 한칸 내리는 함수 

int main() {
    setcursortype(NOCURSOR); //커서지우기 
    reset();

    for (cnt = 0;; cnt++) {
        if (cnt % 10 == 0) new_signal();    //카운트가 10번마다 신호를 하나 만듦 
        draw();
        move();
        Sleep(50); // 0.05초간 딜레이(최소프레임속도) 
    }
}

void reset(void) {
    int i;

    srand((unsigned int)time(NULL));

    for (i = 0; i < MAX_NUM; i++) { //신호 스위치를 전부 off로 초기화 
        S[i].signal_on = OFF;
    }
}
void new_signal(void) {
    int i, j;

    for (i = 0; i < MAX_NUM; i++) { //새로운 신호를 하나 만듦 
        if (S[i].signal_on == OFF) {
            S[i].signal_on = ON;
            S[i].ch = rand() % 95 + 32; // ASCII 32번부터 127번중에 하나 선택 
            S[i].x = rand() % 80;
            S[i].y = 0;
            S[i].speed = rand() % 20 + 1;
            break;
        }
    }

    for (j = 0; j < 4; j++) { //신호를 지우는 신호를 4개 생성 
        for (i = 0; i < MAX_NUM; i++) {
            if (S[i].signal_on == OFF) {
                S[i].signal_on = ON;
                S[i].ch = ' '; // move함수에서 ch가 ' '인경우 지우개가 됩니다. 
                S[i].x = rand() % 80;
                S[i].y = 0;
                S[i].speed = 1; //지우는건 빨리빨리 
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
        if (S[i].signal_on == ON && S[i].y == 23) { //마지막줄에 도달하면 스위치를 off로 종료함 
            S[i].signal_on = OFF;
        }

        if (S[i].signal_on == ON && cnt % S[i].speed == 0) {
            if (rand() % 24 == 0) S[i].ch = ' '; // 24분의 1확률로 신호를 지우개로 바꿈 
            if (S[i].ch != ' ') S[i].ch = rand() % 95 + 32; //신호가 ' '인 경우는 계속 ' '만 출력 
            S[i].y++;
        }
    }
}

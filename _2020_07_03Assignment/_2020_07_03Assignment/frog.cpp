// 원본 게임에서 제외된 기능 : 
// 1.시간 제한, 2.가라앉는 뗏목. 3.친구 개구리, 4.꽃, 5.구멍의 악어. 6.악어 뗏목
#include "Turboc.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define MAX 256

// 차로 - 차 또는 통나무의 생성 규칙
struct Lane
{
    int y;               // y 좌표
    int arWait[10];         // 다음 차 생성까지 대기 시간 목록
    int nFrame;            // 차의 속도
    int Delta;            // 이동 방향
    const char* Shape;         // 차의 모양
    int nWait;            // 현재 대기 시간
    int nStay;            // 대기 시간 카운트
};
Lane L[10] = {
   {4,{300,},18,1,"MMMMMMMMM",},
   {5,{150,150,250,150,},20,-1,"OOOOO",},
   {6,{120,120,200,},12,1,"MMMMMM",},
   {7,{200,200,400,120,},30,-1,"OOO",},
   {8,{100,70,},10,1,"MMMM",},

   {10,{100,300,},10,-1,"Matiz",},
   {11,{50,50,200,},3,1,"Atoz",},
   {12,{150,50,200,},5,-1,"Sonata",},
   {13,{150,200,},5,1,"Visto",},
   {14,{200,},9,-1,"Verna",},
};

// 차 또는 통나무의 정보
struct Car
{
    BOOL exist;
    char* Shape;
    int x, y;
    int Delta;
    int nFrame;
    int nStay;
};
Car C[MAX];
int fx, fy;
int nFrog;
BOOL arHole[5];

void DrawScreen();
void clipputs(int x, int y, const char* str);
void Move(int ch);
void Die();
void MakeCar();
void MoveCar(BOOL bDraw);
void ProcessKey();
int TestDie();

void main()
{
    int i, j;
    int Test;
    BOOL GameOver;

    randomize();
    // 전체 게임 루프
    for (; 1;) {
        nFrog = 4;
        for (i = 0; i < 5; i++) arHole[i] = FALSE;
        GameOver = FALSE;
        // 차, 뗏목 초기화. 처음부터 차와 뗏목이 어느 정도 있어야 한다.
        for (j = 0; j < MAX; j++) {
            C[j].exist = FALSE;
        }
        j = 2000 + random(1000);
        for (i = 0; i < j; i++) {
            MakeCar();
            MoveCar(FALSE);
        }

        // 개구리 하나에 대한 루프
        for (; 2;) {
            DrawScreen();
            fx = 30; fy = 16;

            // 개구리가 죽거나 구멍에 들어갈 때까지의 루프
            for (; 3;) {
                MakeCar();
                MoveCar(TRUE);
                ProcessKey();
                gotoxy(fx, fy); _putch('F');

                Test = TestDie();
                if (Test == 1) {
                    nFrog--;
                    if (nFrog == 0) {
                        gotoxy(32, 20); puts(" GAME OVER "); delay(2000);
                        GameOver = TRUE;
                    }
                    break;
                }
                else if (Test == 2) {
                    if (arHole[0] * arHole[1] * arHole[2] * arHole[3] * arHole[4]) {
                        gotoxy(32, 20); puts(" Perfect "); delay(2000);
                        GameOver = TRUE;
                    }
                    break;
                }
                delay(20);
            }
            if (GameOver) break;
        }
    }
}

// 화면 그림
void DrawScreen()
{
    int i;

    clrscr();
    gotoxy(0, 2); puts("############################################################");
    gotoxy(0, 3); puts("######### ######### ######### ######### ######### ##########");
    gotoxy(0, 9); puts("............................................................");
    gotoxy(0, 15); puts("............................................................");
    for (i = 0; i < 5; i++) {
        if (arHole[i]) { gotoxy(i * 10 + 9, 3); _putch('F'); }
    }
    gotoxy(0, 17); for (i = 0; i < nFrog - 1; i++) _putch('F');
}

// 새로운 차, 통나무 생성
void MakeCar()
{
    int i, j;

    for (i = 0; i < 10; i++) {
        if (++L[i].nStay == L[i].arWait[L[i].nWait]) {
            L[i].nWait++;
            if (L[i].arWait[L[i].nWait] == 0) {
                L[i].nWait = 0;
            }
            L[i].nStay = 0;
            for (j = 0; j < MAX; j++) {
                if (C[j].exist == FALSE) {
                    C[j].exist = TRUE;
                    C[j].nFrame = C[j].nStay = L[i].nFrame;
                    C[j].Shape = L[i].Shape;
                    C[j].Delta = L[i].Delta;
                    C[j].y = L[i].y;
                    C[j].x = (C[j].Delta == 1 ? -10 : 60);
                    break;
                }
            }
        }
    }
}

// 차와 뗏목 이동
void MoveCar(BOOL bDraw)
{
    int j, tx;
    char tshape[32];

    for (j = 0; j < MAX; j++) {
        if (C[j].exist == FALSE) continue;
        if (--C[j].nStay == 0) {
            C[j].nStay = C[j].nFrame;
            // 뗏목 위에 개구리가 있으면 같이 이동
            if (fy == C[j].y && fx >= C[j].x && fx < C[j].x + (int)strlen(C[j].Shape)) {
                fx += C[j].Delta;
            }
            C[j].x += C[j].Delta;
            // 이동하면서 이전 자리의 잔상 지움
            if (bDraw) {
                if (C[j].Delta == -1) {
                    wsprintf(tshape, "%s ", C[j].Shape);
                    tx = C[j].x;
                }
                else {
                    wsprintf(tshape, " %s", C[j].Shape);
                    tx = C[j].x - 1;
                }
                clipputs(tx, C[j].y, tshape);
            }
            if (C[j].x == -20 || C[j].x == 60) {
                C[j].exist = FALSE;
            }
        }
    }
}

void ProcessKey()
{
    int ch;
    // 개구리 이동
    if (_kbhit()) {
        ch = _getch();
        if (ch == 0xE0 || ch == 0) {
            ch = _getch();
            switch (ch) {
            case LEFT:
            case RIGHT:
            case UP:
            case DOWN:
                Move(ch);
                break;
            }
        }
        else {
            switch (ch) {
            case ESC:
                exit(0);
            }
        }
    }
}

void Move(int ch)
{
    gotoxy(fx, fy);
    if (fy == 9 || fy == 15) {
        _putch('.');
    }
    else {
        _putch(' ');
    }
    switch (ch) {
    case LEFT:
        if (fx > 0) fx--;
        break;
    case RIGHT:
        if (fx < 59) fx++;
        break;
    case UP:
        fy--;
        break;
    case DOWN:
        if (fy < 16) fy++;
        break;
    }
}

// 총돌 판정. 0:아무 일 없음, 1:죽음, 2:구멍에 들어감
int TestDie()
{
    int j;

    // 뗏목위에 타고 있는지 검사
    if (fy >= 4 && fy <= 8) {
        for (j = 0; j < MAX; j++) {
            if (C[j].exist == FALSE || C[j].y != fy) continue;
            if (fx >= C[j].x && fx < C[j].x + (int)strlen(C[j].Shape)) {
                break;
            }
        }
        if (j == MAX) {
            Die();
            return 1;
        }
        // 차와 충돌 판정
    }
    else if (fy >= 10 && fy <= 14) {
        for (j = 0; j < MAX; j++) {
            if (C[j].exist == FALSE || C[j].y != fy) continue;
            if (fx >= C[j].x && fx < C[j].x + (int)strlen(C[j].Shape)) {
                Die();
                return 1;
            }
        }
        // 구멍에 들어갔는지 검사
    }
    else if (fy == 3) {
        if (fx % 10 == 9 && arHole[fx / 10] == FALSE) {
            arHole[fx / 10] = TRUE;
            return 2;
        }
        else {
            Die();
            return 1;
        }
    }
    return 0;
}

// 좌우 오른쪽 클리핑 문자열 출력 함수
void clipputs(int x, int y, const char* str)
{
    int len = strlen(str);
    const char* p = str;

    if (x < 0) {
        if (-x > len) return;
        p += -x;
        x = 0;
    }
    gotoxy(x, y);
    for (; x < 60 && *p; x++) {
        printf("%c", *p++);
    }
}

// 사망 처리 - 세 번 깜박임
void Die()
{
    int i;

    for (i = 0; i < 3; i++) {
        gotoxy(fx, fy); _putch(' ');
        delay(200);
        gotoxy(fx, fy); _putch('F');
        delay(200);
    }
}

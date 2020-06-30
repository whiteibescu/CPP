// ���� ���ӿ��� ���ܵ� ��� : 
// 1.�ð� ����, 2.����ɴ� �¸�. 3.ģ�� ������, 4.��, 5.������ �Ǿ�. 6.�Ǿ� �¸�
#include "Turboc.h"

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27
#define MAX 256

// ���� - �� �Ǵ� �볪���� ���� ��Ģ
struct Lane
{
    int y;               // y ��ǥ
    int arWait[10];         // ���� �� �������� ��� �ð� ���
    int nFrame;            // ���� �ӵ�
    int Delta;            // �̵� ����
    const char* Shape;         // ���� ���
    int nWait;            // ���� ��� �ð�
    int nStay;            // ��� �ð� ī��Ʈ
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

// �� �Ǵ� �볪���� ����
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
    // ��ü ���� ����
    for (; 1;) {
        nFrog = 4;
        for (i = 0; i < 5; i++) arHole[i] = FALSE;
        GameOver = FALSE;
        // ��, �¸� �ʱ�ȭ. ó������ ���� �¸��� ��� ���� �־�� �Ѵ�.
        for (j = 0; j < MAX; j++) {
            C[j].exist = FALSE;
        }
        j = 2000 + random(1000);
        for (i = 0; i < j; i++) {
            MakeCar();
            MoveCar(FALSE);
        }

        // ������ �ϳ��� ���� ����
        for (; 2;) {
            DrawScreen();
            fx = 30; fy = 16;

            // �������� �װų� ���ۿ� �� �������� ����
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

// ȭ�� �׸�
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

// ���ο� ��, �볪�� ����
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

// ���� �¸� �̵�
void MoveCar(BOOL bDraw)
{
    int j, tx;
    char tshape[32];

    for (j = 0; j < MAX; j++) {
        if (C[j].exist == FALSE) continue;
        if (--C[j].nStay == 0) {
            C[j].nStay = C[j].nFrame;
            // �¸� ���� �������� ������ ���� �̵�
            if (fy == C[j].y && fx >= C[j].x && fx < C[j].x + (int)strlen(C[j].Shape)) {
                fx += C[j].Delta;
            }
            C[j].x += C[j].Delta;
            // �̵��ϸ鼭 ���� �ڸ��� �ܻ� ����
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
    // ������ �̵�
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

// �ѵ� ����. 0:�ƹ� �� ����, 1:����, 2:���ۿ� ��
int TestDie()
{
    int j;

    // �¸����� Ÿ�� �ִ��� �˻�
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
        // ���� �浹 ����
    }
    else if (fy >= 10 && fy <= 14) {
        for (j = 0; j < MAX; j++) {
            if (C[j].exist == FALSE || C[j].y != fy) continue;
            if (fx >= C[j].x && fx < C[j].x + (int)strlen(C[j].Shape)) {
                Die();
                return 1;
            }
        }
        // ���ۿ� ������ �˻�
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

// �¿� ������ Ŭ���� ���ڿ� ��� �Լ�
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

// ��� ó�� - �� �� ������
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

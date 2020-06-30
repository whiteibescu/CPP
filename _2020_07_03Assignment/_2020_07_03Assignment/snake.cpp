#include "Turboc.h"
#pragma warning (disable:4996)

#define QS 1600
#define _putchxy(x,y,ch) { gotoxy(x,y);putch(ch); }
void InitStage(int stage);
BOOL MoveSnake();
void ProcessKey();
int getchcon(int x, int y);
void waitanykey();

struct tag_Point {
    int x, y;
};
tag_Point snake[QS];
tag_Point now;
int head, tail;
int inctail;
enum tag_Dir { LEFT = 75, RIGHT = 77, UP = 72, DOWN = 80 };
tag_Dir dir;
int life;
int maxnumber;
int speed;
int multi;
int stage;

void main()
{
    int number;
    int ch;
    int x, y;

    life = 5;
    randomize();
    setcursortype(NOCURSOR);
    for (;;) {
        InitStage(stage);
        gotoxy(0, 23); printf("�������� : %d", stage + 1);
        gotoxy(20, 23); printf("���� �� : %d", life);
        for (number = 0; number < maxnumber; number++) {
            gotoxy(40, 23); printf("���� ���� : %d ", maxnumber - number);
            gotoxy(60, 23); printf("���� ���� : 2 ");
            // ������ �ڸ��� ���ο� ���ڸ� �����Ѵ�.
            do {
                x = random(80);
                y = random(22);
            } while (getchcon(x, y) != ' ');
            gotoxy(x, y); printf("%d", random(9) + 1);

            // ���� ���� �����̸� ��� ����ϸ� �������� ���� ��ȸ�� �ش�
            if (number == 0) {
                ch = _getch();
                if (ch == 0xE0) {
                    _getch();
                }
                else {
                    if (ch == 27) {
                        setcursortype(NORMALCURSOR);
                        exit(0);
                    }
                    if (tolower(ch) == 'n') {
                        stage = (stage == 4 ? 0 : stage + 1);
                        break;
                    }
                    if (tolower(ch) == 'p') {
                        stage = (stage == 0 ? 4 : stage - 1);
                        break;
                    }
                }
            }

            // �� �̵� ����
            if (MoveSnake() == TRUE) {
                if (--life == 0) {
                    gotoxy(12, 20);
                    puts("������ �������ϴ�. �׸� ��� ������ �����ϼ���.");
                    return;
                }
                delay(1500);
                break;
            }
        }
        if (number == maxnumber) {
            gotoxy(12, 20);
            puts("�����մϴ�. �ƹ� Ű�� �����ø� ���� ���������� ���ϴ�.");
            waitanykey();
            stage++;
        }
    }
}

// �������� �ʱ�ȭ
void InitStage(int stage)
{
    int i;

    clrscr();
    snake[0].x = 5; snake[0].y = 5;
    snake[1].x = 6; snake[1].y = 5;
    snake[2].x = 7; snake[2].y = 5;
    gotoxy(5, 5); puts("##S");
    head = 2;
    tail = 0;
    inctail = 0;
    now.x = 7;
    now.y = 5;
    dir = RIGHT;

    // �ٱ��� ���� �׸���.
    for (i = 0; i < 80; i++) {
        _putchxy(i, 0, 'M');
        _putchxy(i, 22, 'M');
    }
    for (i = 0; i < 23; i++) {
        _putchxy(0, i, 'M');
        _putchxy(79, i, 'M');
    }

    // ������������ ��ֹ��� ������ �׸��� ���̵��� �����Ѵ�.
    switch (stage) {
    case 0:
        maxnumber = 5; speed = 150; multi = 3;
        for (i = 30; i <= 50; i++) { _putchxy(i, 11, 'M'); }
        break;
    case 1:
        maxnumber = 10; speed = 100; multi = 5;
        for (i = 20; i <= 60; i++) { _putchxy(i, 7, 'M'); _putchxy(i, 14, 'M'); }
        break;
    case 2:
        maxnumber = 15; speed = 80; multi = 6;
        for (i = 20; i < 60; i++) { _putchxy(i, 11, 'M'); }
        for (i = 6; i <= 16; i++) { _putchxy(40, i, 'M'); }
        break;
    case 3:
        maxnumber = 20; speed = 60; multi = 7;
        for (i = 20; i < 60; i++) {
            if (i < 30 || i > 50) {
                _putchxy(i, 7, 'M');
                _putchxy(i, 14, 'M');
            }
        }
        for (i = 7; i < 15; i++) { _putchxy(20, i, 'M'); _putchxy(60, i, 'M'); }
        break;
    case 4:
        maxnumber = 1970; speed = 50; multi = 9;
        break;
    }
}

// ���� �̵���Ų��. �׾����� TRUE�� �����Ѵ�.
BOOL MoveSnake()
{
    int headch;
    int len;
    int prev;

    for (;;) {
        gotoxy(60, 23);
        len = head - tail;
        if (len < 0) len += QS;
        printf("���� ���� : %d ", len);
        ProcessKey();

        switch (dir) {
        case LEFT:
            now.x--;
            break;
        case RIGHT:
            now.x++;
            break;
        case UP:
            now.y--;
            break;
        case DOWN:
            now.y++;
            break;
        }

        // �Ӹ� ��ĭ ����
        head = (head == QS - 1 ? 0 : head + 1);
        snake[head] = now;

        // ���� ��ĭ ����. �� �þ�� �ִ� ���̸� �� �ڸ��� �ִ´�.
        if (inctail == 0) {
            tail = (tail == QS - 1 ? 0 : tail + 1);
        }
        else {
            inctail--;
        }

        // �Ӹ��� �׸��� ���� �Ӹ� ��ġ�� ���ڸ� �̸� �о� ���ƾ� �Ѵ�.
        headch = getchcon(now.x, now.y);
        _putchxy(snake[head].x, snake[head].y, 'S');
        prev = (head == 0 ? QS - 1 : head - 1);
        _putchxy(snake[prev].x, snake[prev].y, '#');
        prev = (tail == 0 ? QS - 1 : tail - 1);
        _putchxy(snake[prev].x, snake[prev].y, ' ');

        // ���� ��ġ�� ������ �ƴϸ� ��򰡿� �ε��� ����
        if (headch != ' ') {
            break;
        }
        delay(speed);
    }

    // ���̳� �ڱ� ������ �ε������� ���� ����
    if (headch == 'M' || headch == '#') {
        return TRUE;
    }
    // ���� ������ multi �踸ŭ ������ �ø���. �þ�� �ִ� ���̶�� �����ȴ�.
    inctail += (headch - '0') * multi;
    return FALSE;
}

// Ű �Է��� ó���Ѵ�.
void ProcessKey()
{
    int ch;

    if (!_kbhit()) {
        return;
    }
    ch = _getch();
    if (ch == 0xE0 || ch == 0) {
        ch = _getch();
        switch (ch) {
        case LEFT:
            // ���� �ݴ� �������δ� ��ȯ�� �� ����.
            if (dir != RIGHT) dir = LEFT;
            break;
        case RIGHT:
            if (dir != LEFT) dir = RIGHT;
            break;
        case UP:
            if (dir != DOWN) dir = UP;
            break;
        case DOWN:
            if (dir != UP) dir = DOWN;
            break;
        }
    }
    else {
        switch (tolower(ch)) {
        case 27:
            setcursortype(NORMALCURSOR);
            exit(0);
        case ' ':
            waitanykey();
            break;
        }
    }
}

// ȭ���� x,y��ġ�� �ִ� ���ڸ� �����Ѵ�.
int getchcon(int x, int y)
{
    COORD Cur;
    Cur.X = x;
    Cur.Y = y;
    TCHAR Char;
    DWORD dwRead;

    ReadConsoleOutputCharacter(GetStdHandle(STD_OUTPUT_HANDLE),
        &Char, 1, Cur, &dwRead);
    return Char;
}

// ������ Ű �ϳ��� ������ ������ ����Ѵ�.
void waitanykey()
{
    int ch;

    ch = _getch();
    if (ch == 0xE0 || ch == 0) {
        _getch();
    }
}

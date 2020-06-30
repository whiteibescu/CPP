#include "Turboc.h"

#define ESC 27
#define MAXENEMY 10
#define MAXBALL 20
#define MAXBULLET 5

int fx;
int Score;
struct tag_Enemy
{
    BOOL exist;
    int Type;
    int x, y;
    int Delta;
    int nFrame;
    int nStay;
} Enemy[MAXENEMY];
struct tag_Ball
{
    BOOL exist;
    int x, y;
    int nFrame;
    int nStay;
} Ball[MAXBALL];
const char* arEnemy[] = { " ;:^:; "," zZWZz ", " oO@Oo ", " <-=-> " };
struct tag_Bullet
{
    BOOL exist;
    int x, y;
} Bullet[MAXBULLET];

BOOL IsKeyDown(int Key)
{
    return ((GetAsyncKeyState(Key) & 0x8000) != 0);
}

void main()
{
    int ch;
    int i, j;
    BOOL bFound;
    int count;

    randomize();
    setcursortype(NOCURSOR);
    while (TRUE) {
        clrscr();
        fx = 40;
        Score = 0;
        for (i = 0; i < MAXENEMY; i++) Enemy[i].exist = FALSE;
        for (i = 0; i < MAXBALL; i++) Ball[i].exist = FALSE;
        for (i = 0; i < MAXBULLET; i++) Bullet[i].exist = FALSE;

        for (count = 0;; count++) {
            // �¿� �̵� ó��
            if (count % 5 == 0) {
                if (IsKeyDown(VK_LEFT)) {
                    if (fx > 6) fx--;
                }
                if (IsKeyDown(VK_RIGHT)) {
                    if (fx < 72) fx++;
                }
            }
            // Ű �Է� ó��
            if (_kbhit()) {
                ch = _getch();
                if (ch == 0xE0 || ch == 0) {
                    _getch();
                }
                else {
                    switch (ch) {
                    case ' ':
                        // ���ο� �Ѿ� ����
                        for (i = 0; i < MAXBULLET && Bullet[i].exist == TRUE; i++) { ; }
                        if (i != MAXBULLET) {
                            Bullet[i].x = fx;
                            Bullet[i].y = 23;
                            Bullet[i].exist = TRUE;
                        }
                        break;
                    case ESC:
                        goto end;
                    }
                }
            }

            // ���� ����
            if (random(100) == 0) {
                for (i = 0; i < MAXENEMY && Enemy[i].exist == TRUE; i++) { ; }
                if (i != MAXENEMY) {
                    if (random(2) == 1) {
                        Enemy[i].x = 5;
                        Enemy[i].Delta = 1;
                    }
                    else {
                        Enemy[i].x = 75;
                        Enemy[i].Delta = -1;
                    }
                    for (;;) {
                        Enemy[i].y = random(10) + 1;
                        for (bFound = FALSE, j = 0; j < MAXENEMY; j++) {
                            if (Enemy[j].exist == TRUE && Enemy[j].y == Enemy[i].y) {
                                bFound = TRUE;
                                break;
                            }
                        }
                        if (bFound == FALSE) {
                            break;
                        }
                    }
                    Enemy[i].nFrame = Enemy[i].nStay = random(6) + 1;
                    Enemy[i].Type = random(sizeof(arEnemy) / sizeof(arEnemy[0]));
                    Enemy[i].exist = TRUE;
                }
            }

            // �Ʊ� �Ѿ� �̵� �� ���
            for (i = 0; i < MAXBULLET; i++) {
                if (Bullet[i].exist) {
                    if (count % 3) break;
                    gotoxy(Bullet[i].x, Bullet[i].y); _putch(' ');
                    if (Bullet[i].y == 0) {
                        Bullet[i].exist = FALSE;
                    }
                    else {
                        Bullet[i].y--;
                        gotoxy(Bullet[i].x, Bullet[i].y); _putch('@');
                    }
                }
            }

            // ������ �Ʊ� �Ѿ��� �浹 ����
            for (i = 0; i < MAXENEMY; i++) {
                if (Enemy[i].exist == FALSE || Enemy[i].Type == -1) continue;
                for (j = 0; j < MAXBULLET; j++) {
                    if (Bullet[j].exist == FALSE) continue;
                    if (Enemy[i].y == Bullet[j].y && abs(Enemy[i].x - Bullet[j].x) <= 2) {
                        gotoxy(Bullet[j].x, Bullet[j].y); _putch(' ');
                        Bullet[j].exist = FALSE;
                        Enemy[i].Type = -1;
                        gotoxy(Enemy[i].x - 3, Enemy[i].y);
                        puts(" .,:,. ");
                        Score += 7 - Enemy[i].nFrame;
                        Enemy[i].nFrame = Enemy[i].nStay = 50;
                        break;
                    }
                }
            }

            // ���� �Ѿ� �̵�
            for (i = 0; i < MAXBALL; i++) {
                if (Ball[i].exist == FALSE) continue;
                if (--Ball[i].nStay == 0) {
                    Ball[i].nStay = Ball[i].nFrame;
                    gotoxy(Ball[i].x, Ball[i].y); _putch(' ');
                    if (Ball[i].y >= 23) {
                        Ball[i].exist = FALSE;
                    }
                    else {
                        if (random(5)) {
                            if (Ball[i].x < fx) {
                                Ball[i].x++;
                            }
                            else {
                                Ball[i].x--;
                            }
                        }
                        Ball[i].y++;
                        gotoxy(Ball[i].x, Ball[i].y); _putch('*');
                    }
                }
            }

            // ���� �Ѿ˰� �Ʊ��� �浹 ����
            for (i = 0; i < MAXBALL; i++) {
                if (Ball[i].exist == FALSE) continue;
                if (Ball[i].y == 23 && abs(Ball[i].x - fx) <= 2) {
                    gotoxy(fx - 3, 21); puts("   .   ");
                    gotoxy(fx - 3, 22); puts(" .  . .");
                    gotoxy(fx - 3, 23); puts("..:V:..");
                    delay(500);
                    goto die;
                }
            }

            // ���� �̵� �� ���
            for (i = 0; i < MAXENEMY; i++) {
                if (Enemy[i].exist == FALSE) continue;
                if (--Enemy[i].nStay == 0) {
                    if (Enemy[i].Type == -1) {
                        gotoxy(Enemy[i].x - 3, Enemy[i].y);
                        puts("       ");
                        Enemy[i].exist = FALSE;
                        continue;
                    }
                    Enemy[i].nStay = Enemy[i].nFrame;
                    if (Enemy[i].x >= 76 || Enemy[i].x <= 4) {
                        Enemy[i].exist = FALSE;
                        gotoxy(Enemy[i].x - 3, Enemy[i].y);
                        puts("       ");
                    }
                    else {
                        Enemy[i].x += Enemy[i].Delta;
                        gotoxy(Enemy[i].x - 3, Enemy[i].y);
                        puts(arEnemy[Enemy[i].Type]);

                        // �Ѿ� �߻�
                        if (random(40) == 0) {
                            for (j = 0; j < MAXBALL && Ball[j].exist == TRUE; j++) { ; }
                            if (j != MAXBALL) {
                                Ball[j].x = Enemy[i].x + 2;
                                Ball[j].y = Enemy[i].y + 1;
                                Ball[j].nFrame = Ball[j].nStay = Enemy[i].nFrame * 6;
                                Ball[j].exist = TRUE;
                            }
                        }
                    }
                }
            }

            // ������ �� ���� ���
            gotoxy(fx - 3, 23);
            puts(" <<A>> ");
            gotoxy(0, 24);
            printf("����=%d", Score);

            // �ʴ� 100 ������
            delay(10);
        }
    die:
        {; }
    }
end:
    setcursortype(NORMALCURSOR);
}

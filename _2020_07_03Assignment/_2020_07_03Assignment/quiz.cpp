#include "Turboc.h"
#include <ctype.h>
#include "../Turboc.h"

// ���� �ϳ��� ���� ������ ������ ����ü
struct tag_Munje {
    const char* Question;
    const char* Case[3];
    const int Answer;
    BOOL Used;
};

// ���� �迭
struct tag_Munje Munje[] = {
   {"���� Ÿ���� �⺻���� �ƴ� ����","������", "�迭","������",2,FALSE},
   {"���� �� �ݺ����� �ƴ� ����","switch", "for","while",1,FALSE},
   {"����ü�� ������ �� ����ϴ� Ű�����","int", "goto","struct",3,FALSE},
   {"���� �� ���� ũ�Ⱑ ū Ÿ����","int", "double","char",2,FALSE},
   {"�������� ������ �� ����ϴ� Ű�����","enum", "alias","define",1,FALSE},
   {"���� �� ���� �����ڴ�","++", "?","=",1,FALSE},
   {"���� �迭�� ������ �ٲ� �� ����ϴ� �Լ���","strassign", "strmove","strcpy",3,FALSE},
   {"����ü�� ����� ���� �� ����ϴ� �����ڴ�","->", "*",".",3,FALSE},
   {"������ Ÿ���� �ƴ� ����","unsigned", "short","float",3,FALSE},
   {"C ���α׷����� �ݵ�� �ʿ��� �Լ���","entry", "main","WinMain",2,FALSE},
};

void main()
{
    int num;
    int count;
    int i;
    char ch;

    randomize();
    for (count = 0; count < 5; count++) {
        // �������� ���� ���� �ϳ��� ����.
        do {
            num = random(sizeof(Munje) / sizeof(Munje[0]));
        } while (Munje[num].Used == TRUE);
        Munje[num].Used = TRUE;

        // ������ ����Ѵ�.
        clrscr();
        gotoxy(2, 2);
        printf("%s?", Munje[num].Question);
        for (i = 0; i < 3; i++) {
            gotoxy(2, 5 + i * 2);
            printf("(%d) %s", i + 1, Munje[num].Case[i]);
        }
        gotoxy(2, 12);
        printf("1,2,3 �� �ϳ��� �����ϼ���.�������� Q : ");

        // ������ �Է¹޾� ������ �ش�.
        ch = _getch();
        if (tolower(ch) == 'q') {
            break;
        }
        ch = ch - '0';
        gotoxy(2, 15);
        if (ch == Munje[num].Answer) {
            printf("�����Դϴ�.");
        }
        else {
            printf("Ʋ�Ƚ��ϴ�. ������ %d���Դϴ�.", Munje[num].Answer);
        }
        delay(1000);
    }

    gotoxy(2, 17);
    printf("�����ϼ̽��ϴ�.\n");
}

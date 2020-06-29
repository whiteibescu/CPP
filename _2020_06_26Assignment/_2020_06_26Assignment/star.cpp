/*
1. random하게 80*25안의 임의의 위치에 100개의 별이
생성되고 역순으로 지워지는 프로그램
*/

#include "turboc.h"
/*
1.구조체배열생성
2.각 배열에 별을 출력
3.역순으로 제거
*/
class Position
{
private:
    int x;
    int y;
public:
    void initPos()
    {
        x = random(80);
        y = random(25);
    }
    void outPos()
    {
        gotoxy(x, y);
        printf("*");
    }
    void ereasePos()
    {
        gotoxy(x, y);
        printf(" ");
    }
};

int main()
{
    Position arPos[100];
    memset(arPos, 0, sizeof(arPos));

    randomize();
    for (int i = 0; i < 100; i++) {
        arPos[i].initPos();
        arPos[i].outPos();
        delay(50);

    }
    delay(1000);
    for (int i = 99; i >= 0; i--) {
        arPos[i].ereasePos();

        delay(50);
    }
}

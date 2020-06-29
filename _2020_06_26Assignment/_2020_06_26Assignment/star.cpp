/*
1. random�ϰ� 80*25���� ������ ��ġ�� 100���� ����
�����ǰ� �������� �������� ���α׷�
*/

#include "turboc.h"
/*
1.����ü�迭����
2.�� �迭�� ���� ���
3.�������� ����
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

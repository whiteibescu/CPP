#include "Human.h"
#include "Developer.h"

void main()
{
	Human human;
	human.play();

	Developer dev;
	dev.play();

	/*C++������ �������̶�� ������ �����ϱ� ���ؼ�
	������ ���� ������ �����Ͽ���
	�θ��� ������ ���� = �ڽ� ��ü*/
	Human* hu = &dev;
	hu->play();		// Human::play() ȣ��
}
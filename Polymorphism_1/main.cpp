#include "Human.h"
#include "Developer.h"

void main()
{
	Human human;
	human.play();

	Developer dev;
	dev.play();

	/* play() �Լ��� ���� �� 
	virtual Ű���带 �ٿ��ָ�
	�θ� ������ ������ ����
	�ڽ� ��ü�� �Լ��� ȣ���� �� �ִ�
	*/
	Human* hu = &dev;
	hu->play();		
}
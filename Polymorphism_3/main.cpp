#include "Human.h"
#include "Developer.h"

void main()
{
	Human human;
	human.play();

	Developer dev;
	dev.play();

	/*
	virtual : �����Լ�
	          ��ǻ� (��ü�� ����) �Լ�
	*/
	// �ּ� = ��ü(��ü)
	Human* hu = &dev;
	hu->play();		
}
#pragma once
#include <combaseapi.h>
/* 
�߻� �޼��尡 ���ԵǾ� �����Ƿ�
�߻� Ŭ�����̴�.

��, ��� �޼���(��� �Լ�)�� �߻� �޼����̹Ƿ�
�������̽���� �� ���� ����Ѵ�

<�������̽��� ����>
1) Ŭ���� ������ �迭 : ����
2) �Ű�����
3) ������ �ڽ� ��ü�� ��� ���Ҹ�
4) ������ ����
5) ����, ������ ����
*/
//#define interface class

interface StarUnit
{
public:
	/* ���� ���� �Լ�
	 (�߻� �޼���)
	*/
	virtual void move() = 0;
	virtual void attack() = 0;
	virtual void die() = 0;
};


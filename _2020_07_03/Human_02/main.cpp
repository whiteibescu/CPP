#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"
/*
1) Overloading(����)
; ������ �Լ����� ����
(��, �Ű������� �ٸ���)
2) Overriding (������)
; �ֿ켱��
������ ���� ������.
; �θ� ������ �Լ��� �ٽ� ����(������)
  �� �Լ��� �ֿ켱�̴�
*/

void main()
{
	Developer dev("ȫ�浿", 24, 3, 12);

	// Human�� ������ �״��
	dev.eat();		

	// ComputerEnginner�� ������ �Լ��� Ȯ��
	// Overriding : ������, ������ �Ϳ��� Ȯ��/����
	dev.overTime(); 

	dev.info(); // Ȯ�� ������

	dev.neverEndingStudy(); // ���� �߰�

	dev.sleep(); // ���� ������

}



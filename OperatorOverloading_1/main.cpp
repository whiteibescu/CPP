/* 
<������ �����ε�>
; ������ == ��ȣ
  ��ȣ => �������� ����
; Ŭ��������
  �����ڰ� �����ȣ�� �������� ������ ���
  ������(����)�ϰ� ���ִ� ������ν�
  �����ڸ� �Լ��� �����ϰ� ���ش�
*/

#include "Position.h"

void main()
{
	Position pos(10, 10);
	Position pos1 = pos++;
	pos1.showPosition();
	pos.showPosition();
	//pos++++;	// �Ұ����ϴ�
}
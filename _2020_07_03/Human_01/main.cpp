#include "Human.h"
#include "ComputerEngineer.h"
#include "Developer.h"
#include "ServerManager.h"

void main()
{
	/* Developer�� �����ڰ� ȣ��ȴ�
	 �׷��� Developer �������� member initialize������
	 ComputerEngineer ���������� ���� �����ϵ��� �Ͽ���
	 ComputerEngineer�� member initialize��������
	 Human ���������� ���� �����ϵ��� �Ͽ���
	 �θ� �����ڸ� ���ؼ� ������ ��� ������ �ʱ�ȭ�Ͽ���
	*/
	Developer dev("ȫ�浿", 24, 3, 12);
	dev.eat();
	dev.overTime();
	dev.info();
}
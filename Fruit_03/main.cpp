/* <���� ���� ����>
1) class�� ����ο� �����η� �и��Ѵ�
---->  2) ����δ� h(�������)�� �����Ѵ�
---->  3) �����δ� cpp(�ҽ�����)�� �����Ѵ�
---->  4) �ش� ���Ͽ� ���� ������ #include�� ���ش�
*/
#include "FruitSeller.h"
#include "FruitBuyer.h"

void main()
{
	FruitSeller seller;
	FruitBuyer buyer;
	buyer.buyApple(seller, 2000);

	seller.showSaleResult();
	buyer.showBuyResult();
}
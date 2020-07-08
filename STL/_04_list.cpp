/*
list �ڷᱸ�� == Sequence Container
- ������ �ִ�
- �����ȴ�
1) �迭 : ���������� ������
          ���� ~ ������ �˻�
2) ��ũ�帮��Ʈ : �������� ������
3) �� : �迭/��ũ�帮��Ʈ�� �����
        ����� ����
*/
#include <iostream>
#include <list>

using namespace std;

void main()
{
    /* ��ũ�� ����Ʈ
    ��������
    �߰� ����/������ ������ ����
    */
    const int DATA_NUM = 6;
    list<int> llist;
    for (int i = 0; i < DATA_NUM; i++)
        llist.push_back(i * 2);

    // �ݺ��ڷ� ����
    list<int>::iterator it = llist.begin();
    ++it;   // 2��° ��ġ�� �̵�
    /* 99�� 2��° ��ġ�� ����
     it�� 3��°�� ����Ų��.
     */
    llist.insert(it, 99);
    llist.erase(it);

    // ���
    it = llist.begin();
    while (it != llist.end())
        cout << *it++ << ", ";
    cout << endl;
}
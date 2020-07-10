/* associate container(���� �����̳�)
; Ư�� ���� ã�� ��(�˻�) ���� ���� �ڷᱸ��
a) hash Algorithm���� ��ȯ
b) hash���� ���뿡 ���� ������ ũ���� ������ ��ȯ�ȴ�
   a -> hash -> 89ac7803
   ȫ�浿 -> hash -> 1c90dfd3
   ���ع��� ��λ��� ������ �⵵�� -> hash -> 22fc09da
   �Ҽ� ���� ���� -> hash -> 90acf102d
   ���ع���
    ��λꤷ
   �Ӹ�����
   �⵵�� 
   �ϴ�����
c) hash ������ ����
d) �ش� ��ġ�� �ٷ� ã�ư���
1) set
   Data -> hash -> key
   Data ---------> value
   ������ ��ü�� Ű�̸鼭 ���ÿ� ���̴�.
   �����ͷ� �˻�
2) map(dictionary, hashTable, hashMap)
   key -> hash
   Data
   Ű�� ����ؼ� ���� �˻��Ѵ�

   *������ ����ӵ��� ����Ʈ �������� ������
     hash��ȯ -> ����
   *Ư�� �� �˻��� ���� ���� ����
*/
#include <iostream>
#include <set>
using namespace std;

void main()
{
    string fruitArr[] = {
        "kiwi", "apple", "pineapple",
        "orange", "lemon", "banana"
    };
    set<string> fruitSet;
    int arrLen = sizeof(fruitArr) / sizeof(fruitArr[0]);
    for (int i = 0; i < arrLen; i++)
        fruitSet.insert(fruitArr[i]);

    // set ���� ���
    set<string>::iterator it = fruitSet.begin();
    while (it != fruitSet.end()) {
        cout << *it++ << endl;
    }
    cout << endl << endl;

    // �˻�
    string testArr[] = {
        "strawberry", "banana", "watermelon",
        "apple", "melon", "kiwi"
    };
    arrLen = sizeof(testArr) / sizeof(testArr[0]);
    for (int i = 0; i < arrLen; i++) {
        set<string>::iterator found =
            fruitSet.find(testArr[i]);
        if (found != fruitSet.end())
            cout << *found << " found in the set.\n";
    }
}
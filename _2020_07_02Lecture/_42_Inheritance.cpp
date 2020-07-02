#include <iostream>

using namespace std;

class Animal
{
private:
	string name = "����";
public:
	void breathe() {
		cout << "���� ����" << endl;
	}
	void sleep() {
		cout << "���� �ܴ�" << endl;
	}
	void move() {
		cout << "�����δ�" << endl;
	}
	string getName() {
		return this->name;
	}
};

class Mammals : public Animal
{
public:
	void drinkMilk() {
		cout << "������ ���Ŵ�" << endl;
	}
};

class Tiger : public Mammals
{
};

class Lion : public Mammals
{
};

void main()
{
	Tiger tiger;
	Lion lion;

	cout << tiger.getName() << endl;
	tiger.breathe();
	tiger.move();
	tiger.sleep();
	tiger.drinkMilk();

	cout << endl;

	cout << lion.getName() << endl;
	lion.breathe();
	lion.move();
	lion.sleep();
	tiger.drinkMilk();


	
}
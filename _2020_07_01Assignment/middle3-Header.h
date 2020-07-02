#pragma once
#define _CRT_SECURE_NO_WARNINGS
#define NAME_LEN		20
#define TEL_LEN			20
#define MAX_PERSON_NUM	100

class Person
{

private:
	char* name;
	char* phone;

public:
	Person() {
		name = new char[NAME_LEN];
		phone = new char[TEL_LEN];
	}
	~Person() {
		delete[] name;
		delete[] phone;
	}


public:
	// getter
	char* getName() {
		return name;
	}
	// setter
	void setName(char* _name)
	{
		strncpy(name, _name, strlen(_name));
		name[strlen(_name)] = '\0';// 0, NULL
	}
	char* getPhone()
	{
		return phone;
	}
	void setPhone(char* _phone)
	{
		strncpy(phone, _phone, strlen(_phone));
		phone[strlen(_phone)] = '\0';
	}
	void showPerson()
	{
		printf("name: %s\n", name);
		printf("phone: %s\n", phone);
	}
};

// C++������ �̷� �Լ��� '���� �Լ�'�� �θ���
void ShowMenu();
void InsertTelInfo(Person* par, int* pnum);
void DeleteTelInfo(Person* par, int* pnum);
void SearchTelInfo(Person* par, int num);
void PrintAll(Person* par, int num);
void ClearScreen();

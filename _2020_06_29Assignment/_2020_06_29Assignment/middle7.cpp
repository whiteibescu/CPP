#include <iostream>
#include <string>

using namespace std;

int main()
{
	char name[20];
	char address[200];
	int age;

	cout << "Please Enter Your Name : " << endl;
	cin.getline(name, 20);

	cout << "Please Enter Your Address : " << endl;
	cin.getline(address, 200);

	cout << "Please Enter Your Age : " << endl;
	cin >> age;

	cout << "Name : " << name <<"\n" << "Address : " <<address << "\n" << "Age : " <<age << endl;
}
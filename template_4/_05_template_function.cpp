#include <iostream>

using namespace std;

template<typename T>
T add(T a, T b) {
	cout << "General Template" << endl;
	return a + b;
}

/*
<���ø��� Ưȭ>
T�� char*�� ���� ���� �Ⱦ���
�̰����� ó���ϰڴ�.
*/
template<>
char* add(char* a, char* b) {
	cout << "Special Template" << endl;
	int len = strlen(a) + strlen(b) + 1;
	char* p = new char[len]();
	strncpy_s(p, len, a, strlen(a));
	strncpy_s(p + strlen(a), 
		len - strlen(a), b, strlen(b));
	p[strlen(a) + strlen(b)] = 0;
	return p;
}

void main()
{
	cout << add<int>(100, 200) << endl;
	cout << add<double>(2.5, 3.4) << endl;
	cout << add<char*>((char*)"���ѹα�", 
						(char*)" �λ�") << endl;
	cout << add<string>("���ѹα�", " �λ�");
}
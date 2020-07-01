#include <iostream>
#include <string>
using namespace std;
class Date {
public:
    int year, month, day;
    Date(int year, int month, int day);
    Date(string date);
    void show();
    int getYear();
    int getMonth();
    int getDay();
};
Date::Date(int a, int b, int c) { //정수 매개변수를 갖는 생성자
    year = a; month = b; day = c;
}
Date::Date(string a) { // 문자열 매개변수를 갖는 생성자
    year = stoi(a.substr(0, 4));
    month = stoi(a.substr(5, 7));
    day = stoi(a.substr(7, 10));
}
void Date::show() {
    cout << year << "년" << month << "월" << day << "일" << endl;
}
int Date::getYear() {
    return year;
}
int Date::getMonth() {
    return month;
}
int Date::getDay() {
    return day;
}

void main()
{
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << ',' << birth.getMonth() << ',' << birth.getDay() << endl;
}


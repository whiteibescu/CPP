#include <iostream>
#include <string>
using namespace std;

class Histogram {
	string his;
	int len;
	int count[26];
public:
	Histogram(string h) {
		his = h + "\n"; len = 0;
		for (int i = 0; i < h.size(); i++)
			if (isalpha(his.at(i))) len++;
		for (int i = 0; i < 26; i++)
			count[i] = 0;
	}
	void put(string h);
	void putc(char h);
	void print();
};
void Histogram::put(string h) {
	this->his += h;
	for (int i = 0; i < h.size(); i++)
		if (isalpha(h.at(i))) len++;
}
void Histogram::putc(char h) {
	this->his += h;
	if (isalpha(h)) len++;
}
void Histogram::print() {
	cout << his << endl << endl << "ÃÑ ¾ËÆÄºª ¼ö " << len << endl << endl;
	char temp;
	for (int i = 0; i < his.size(); i++) {
		if (isalpha(his.at(i))) {
			temp = tolower(his.at(i));
			count[temp - 97]++;
		}
	}
	for (int i = 0; i < 26; i++) {
		printf("%c (%d)\t: ", 97 + i, count[i]);
		for (int j = 0; j < count[i]; j++)
			cout << "*";
		cout << endl;
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only fools rush in But I Can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}
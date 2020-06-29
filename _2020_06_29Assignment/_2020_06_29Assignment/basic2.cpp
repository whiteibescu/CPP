#include<iostream>
using namespace std;

class Oval {
private:
    int width, height;
public:
    Oval();
    Oval(int a, int b);
    int getWidth();
    int getHeight();
    void set(int w, int h);
    void show();
    ~Oval();
};

Oval::Oval() {
    width = 1;
    height = 1;
}
Oval::Oval(int a, int b) {
    width = a;
    height = b;
}
int Oval::getWidth() {
    return width;
}
int Oval::getHeight() {
    return height;
}
void Oval::set(int w, int h) {
    width = w;
    height = h;
}

void Oval::show() {
    cout << "width = " << width << ", height = " << height << endl;
}

Oval::~Oval() {
    cout << "Oval �Ҹ� : width = " << width << ", height = " << height << endl;
}

#include <iostream>
using namespace std;

// main() �Լ�
int main() {
    Oval a, b(3, 4);
    a.set(10, 20);
    a.show();
    cout << b.getWidth() << ", " << b.getHeight() << endl;
}

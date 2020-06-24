#include <iostream>

using namespace std;

class Mammal {

private:
    char voice[5];

public:
    char* getVoice() {
        return this->voice;
    }
    void setVoice(const char* voice) {
        strcpy_s(this->voice, voice);
    }
    void bark() {
        cout << "�� ������ \"" << this->getVoice() << "\" �ϰ� ��ϴ�." << endl;
    }

};

int main() {
    Mammal dog;
    Mammal cat;
    dog.setVoice("�۸�");
    dog.bark();
    cat.setVoice("�߿�");
    cat.bark();
}
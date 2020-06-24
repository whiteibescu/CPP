#include <iostream>

using namespace std;

typedef struct mammal {
    char voice[5];
    char* getVoice() {
        return this->voice;
    }
    void setVoice(const char* voice) {
        strcpy_s(this->voice, voice);
    }
    void bark() {
        cout << "�� ������ \"" << this->getVoice() << "\" �ϰ� ��ϴ�." << endl;
    }

} Mammal;


int main() {
    Mammal dog;
    Mammal cat;
    dog.setVoice("�۸�");
    dog.bark();
    cat.setVoice("�߿�");
    cat.bark();
}
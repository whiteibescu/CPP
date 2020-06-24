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
        cout << "ÀÌ µ¿¹°Àº \"" << this->getVoice() << "\" ÇÏ°í ¿ó´Ï´Ù." << endl;
    }

};

int main() {
    Mammal dog;
    Mammal cat;
    dog.setVoice("¸Û¸Û");
    dog.bark();
    cat.setVoice("¾ß¿Ë");
    cat.bark();
}
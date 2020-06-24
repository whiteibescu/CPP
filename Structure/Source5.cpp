#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

namespace A {
    int Plus(int a, int b) {
        return a;
    }
}

namespace B {
    char* Plus(const char* a, const char* b) {
        int len = strlen(a);
        int len2 = strlen(b);
        char* str = (char*)malloc(sizeof(char) * (len + len2 + 1));
        memset(str, 0, len + len2 + 1);

        strncpy(str, a, len);
        strncpy(str + len, b, len2);
        return str;
    }
}

void main() {
    int a = 10, b = 20, result;

    const char* str = "아름다운 ";
    const char* str2 = "대한민국";
    char* strResult;

    result = A::Plus(a, b);
    std::cout << result << std::endl;
    strResult = B::Plus(str, str2);

    std::cout << strResult << std::endl;
    free(strResult);
}
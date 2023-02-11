#include <iostream>

using namespace std;

class C1 {
private:
int num1;
int num2;
int *ptr1;

public:
C1(int&& a, int&& b);
C1(int& a, int& b);
C1(const C1& Sp) = default;

void convert_member(int&& val);
void convert_ptr(int&& val);
};

C1::C1(int&& a, int&& b) {
    num1 = a;
    num2 = b;
    a = a + 1;
    ptr1 = new int();
    *ptr1 = 3;
}

C1::C1(int& a, int& b) {
    num1 = a;
    num2 = b;
    a = a + 1;
    ptr1 = new int();
    *ptr1 = 3;
}

void C1::convert_ptr(int&& val) {
    *ptr1 = val;
}

void C1::convert_member(int&& val) {
    num1 = val;
}


// MAIN
int main(void) {
    int zz = 3;
    int zz2 = 3;
    C1 sp1(3,3);
    C1 sp11(zz, zz2);
    C1 sp2(sp1);
    C1 sp3 = sp2;

    sp1.convert_ptr(5);
    sp1.convert_member(100);
    sp2.convert_member(200);
    sp3.convert_member(300);
    return 0;
}

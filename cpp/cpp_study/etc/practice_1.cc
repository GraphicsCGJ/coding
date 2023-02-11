#include <iostream>

using namespace std;

class C1 {
private:
int num1;
int num2;
int *ptr1;

public:
C1(int a, int b);
C1(const C1& Sp) = default;

void convert_member(int&& val);
void convert_ptr(int&& val);
void print();
};

C1::C1(int a, int b) {
    cout << "normal" << endl;
    num1 = a;
    num2 = b;
    ptr1 = new int();
    *ptr1 = 3;
}

void C1::convert_ptr(int&& val) {
    *ptr1 = val;
}

void C1::convert_member(int&& val) {
    num1 = val;
}

void C1::print() {
    cout << typeid(this).name() << '\n';
    cout << "num1" << ": " << num1 << '\n';
    cout << "num2" << ": " << num2 << '\n';
    cout << "ptr1" << ": " << ptr1 << '\n';
    cout << "*ptr1" << ": " << *ptr1 << '\n';
    cout << '\n';
}

// MAIN
int main(void) {
    C1 sp1(3,3);
    C1 sp2(sp1);
    C1 sp3 = sp2;

    sp1.convert_ptr(5);
    sp1.convert_member(100);
    sp2.convert_member(200);
    sp3.convert_member(300);
    sp1.print();
    sp2.print();
    sp3.print();

    return 0;
}

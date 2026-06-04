#include <iostream>
using namespace std;

// Lớp cơ sở gốc
class A {
public:
    int dataA;
    A(int a) : dataA(a) {
        cout << "Goi ham khoi tao A" << endl;
    }
};

// Lớp B kế thừa ảo từ A
class B : virtual public A {
public:
    int dataB;
    B(int a, int b) : A(a), dataB(b) {
        cout << "Goi ham khoi tao B" << endl;
    }
};

// Lớp C kế thừa ảo từ A
class C : virtual public A {
public:
    int dataC;
    C(int a, int c) : A(a), dataC(c) {
        cout << "Goi ham khoi tao C" << endl;
    }
};

// Lớp D đa kế thừa từ B và C
class D : public B, public C {
public:
    int dataD;
    /* 
       Lưu ý quan trọng: Trong kế thừa ảo, lớp dẫn xuất cuối cùng (D) 
       phải có trách nhiệm gọi trực tiếp hàm khởi tạo của lớp gốc (A).
    */
    D(int a, int b, int c, int d) : A(a), B(a, b), C(a, c), dataD(d) {
        cout << "Goi ham khoi tao D" << endl;
    }

    void display() {
        cout << "--- Gia tri cac bien ---" << endl;
        cout << "dataA: " << dataA << endl; // Khong bi loi nhap nhang (ambiguous)
        cout << "dataB: " << dataB << endl;
        cout << "dataC: " << dataC << endl;
        cout << "dataD: " << dataD << endl;
    }
};

int main() {
    D obj(10, 20, 30, 40);
    obj.display();
    return 0;
}
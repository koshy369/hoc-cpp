#include <iostream>
#include <string.h>
using namespace std;

// Lớp cơ sở (Base Class)
class Car {
protected:
    int speed;
    char mark[20];
public:
    // Hàm khởi tạo của lớp cơ sở
    Car(int s, const char* m) {
        speed = s;
        strcpy(mark, m);
        cout << "Goi ham khoi tao Car (Base)" << endl;
    }

    // Hàm hủy của lớp cơ sở(phải có"~")
    ~Car() {
        cout << "Goi ham huy Car (Base)" << endl;
    }
};

// Lớp dẫn xuất (Derived Class) kế thừa công khai từ Car
class Bus : public Car {
private:
    int label; // Số hiệu tuyến bus
public:
    /* 
       Hàm khởi tạo lớp dẫn xuất:
       Sử dụng "Danh sách khởi tạo" (Initialization List) để truyền tham số 
       từ Bus lên cho hàm khởi tạo của Car.
    */
    Bus(int s, const char* m, int l) : Car(s, m) {
        label = l;
        cout << "Goi ham khoi tao Bus (Derived)" << endl;
    }

    // Hàm hủy của lớp dẫn xuất
    ~Bus() {
        cout << "Goi ham huy Bus (Derived)" << endl;
    }

    void display() {
        cout << "Xe: " << mark << " - Toc do: " << speed 
             << " - Tuyen so: " << label << endl;
    }
};

int main() {
    cout << "--- Khoi tao doi tuong Bus ---" << endl;
    Bus myBus(60, "Mercedes", 54);
    myBus.display();

    cout << "--- Ket thuc chuong trinh (Huy doi tuong) ---" << endl;
    return 0;
}
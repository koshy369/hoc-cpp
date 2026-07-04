#include <iostream>
using namespace std;

// 1. ĐỊNH NGHĨA LỚP
class Robot {
// 2. PHẠM VI TRUY NHẬP
private: 
    int nangLuong; // Tuyệt mật, chỉ nội bộ Robot mới được đụng vào

protected: 
    string maKieu; // Cho phép lớp con (nếu có kế thừa sau này) sử dụng

public: 
    // 3. HÀM KHỞI TẠO (Constructor) - Tự gọi khi tạo đối tượng
    Robot(int nl = 100) { 
        nangLuong = nl; 
        cout << "Ting! Robot duoc che tao." << endl; 
    }
    
    // 4. HÀM HỦY (Destructor) - Tự gọi khi đối tượng bốc hơi
    ~Robot() { 
        cout << "Bum! Robot da bi tieu huy." << endl; 
    }

    // Phương thức (Hành động)
    void baoCao() { 
        cout << "Nang luong hien tai: " << nangLuong << "%" << endl; 
    }

    // 5. HÀM BẠN (Friend function) - Kẻ ngoại đạo được cấp phép phá luật
    friend void hackerBaoTri(Robot &r);
};

// Định nghĩa hàm bạn ở bên ngoài (Không thuộc lớp Robot)
void hackerBaoTri(Robot &r) {
    // Dù nangLuong là private, hàm bạn vẫn chọc thẳng vào sửa được!
    r.nangLuong = 9999; 
}

int main() {
    cout << "--- MANG DOI TUONG ---" << endl;
    // 6. MẢNG ĐỐI TƯỢNG: Tạo 1 lúc 2 robot (gọi Constructor 2 lần)
    Robot doiQuan[2]; 

    cout << "\n--- CON TRO & CAP PHAT DONG ---" << endl;
    // 7. CON TRỎ ĐỐI TƯỢNG: Cấp phát bộ nhớ động bằng new
    Robot* robotNanNhan = new Robot(500); 
    
    // Dùng toán tử -> để gọi hàm qua con trỏ
    robotNanNhan->baoCao(); 
    
    // Dùng hàm bạn để thay doi gtri trong private
    hackerBaoTri(*robotNanNhan); 
    cout << "Sau khi bi hack: ";
    robotNanNhan->baoCao();

    // 8. GIẢI PHÓNG BỘ NHỚ
    cout << "\n--- DON DEP ---" << endl;
    delete robotNanNhan; // Bắt buộc dùng delete (gọi Destructor cho robotNanNhan)
    cout<<"----Ket Thuc Chuong Trinh----\n";
    return 0; 
    // Kết thúc hàm main, mảng doiQuan[2] hết hạn sử dụng -> gọi Destructor 2 lần nữa
}
#include <iostream>
#include <string>
#include <thread> // Thư viện để dùng Thread
#include <chrono> // Thư viện để dùng Chrono
#include <fcntl.h>   // cấu hình các chế độ điều khiển tệp (phục vụ _setmode)
#include <io.h> 

using namespace std;

// Đây là một hàm (công việc) sẽ chạy độc lập
void demGiay(int soGiay) {
    for (int i = 1; i <= soGiay; ++i) {
        // In ra số giây hiện tại
        wcout << L"[Luồng phụ] Đang đếm: " << i << L" giây..." << endl;

        // Dùng Chrono để bắt luồng này dừng lại 1 giây
        // standard::this_thread::sleep_for là lệnh "ngủ"
        // chrono::seconds(1) là đơn vị 1 giây
        this_thread::sleep_for(chrono::seconds(1));
    }
    wcout << L"[Luồng phụ] Đã hoàn thành công việc!" << endl;
}

int main() {
    _setmode(_fileno(stdin), _O_U16TEXT);
    _setmode(_fileno(stdout), _O_U16TEXT);
    wcout << L"--- Bat dau chuong trinh ---" << endl;

    // 1. Tạo một luồng mới tên là 't1' và bảo nó thực hiện hàm 'demGiay'
    // Chúng ta truyền số 5 vào làm tham số (đếm đến 5)
    thread t1(demGiay, 5);

    // 2. Trong lúc 't1' đang đếm, chương trình chính (main) vẫn chạy tiếp
    for (int i = 0; i < 3; ++i) {
        wcout << L"[Chương trình chính] Đang làm việc khác..." << endl;
        this_thread::sleep_for(chrono::milliseconds(500)); // Ngủ 0.5 giây
    }

    // 3. Quan trọng: join() giúp chương trình chính đợi luồng 't1' làm xong
    // Nếu không có dòng này, chương trình chính kết thúc và 't1' sẽ bị ngắt giữa chừng
    t1.join();

    wcout << L"--- Ket thuc chuong trinh ---" << endl;

    return 0;
}
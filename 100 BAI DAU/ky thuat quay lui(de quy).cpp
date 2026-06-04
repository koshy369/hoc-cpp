#include <iostream>
using namespace std;

int n;
int a[100]; // Lưu cấu hình hoán vị
bool visited[100]; // Đánh dấu số đã dùng chưa

void inKetQua() {
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int k) {
    for (int i = 1; i <= n; i++) {
        // Nếu số i chưa được dùng thì "bụp" nó
        if (visited[i] == false) {
            a[k] = i;           // Gán giá trị
            visited[i] = true;  // Đánh dấu "đã xài"
            
            if (k == n) {
                inKetQua();     // Đi hết đường thì in
            } else {
                Try(k + 1);     // Chưa xong thì đệ quy đi tiếp
            }
            
            // QUAN TRỌNG NHẤT: Backtracking (Quay lui)
            visited[i] = false; // Trả lại trạng thái để nhánh khác còn dùng
        }
    }
}

int main() {
    cout << "Nhap n: ";
    cin >> n;
    Try(1); // Bắt đầu thử từ vị trí số 1
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> X;
vector<bool> used;

// Hàm xuất cấu hình hiện tại ra màn hình
void printResult() {
    for (int i = 1; i <= N; ++i) {
        cout << X[i] << " ";
    }
    cout << "\n";
}

// Hàm quay lui để thử giá trị cho vị trí thứ i
void Try(int i) {
    for (int v = 1; v <= N; ++v) {
        if (!used[v]) { // Kiểm tra điều kiện logic: v chưa được chọn
            X[i] = v;      // Thử đặt X[i] = v
            used[v] = true; // Đánh dấu v đã được sử dụng

            if (i == N) {
                printResult(); // Đạt đến đích: in kết quả
            } else {
                Try(i + 1);    // Tiến đến vị trí tiếp theo
            }

            used[v] = false; // Bước quay lui (Backtracking): khôi phục trạng thái
        }
    }
}

int main() {
    // Tối ưu hóa I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N)) return 0;

    X.resize(N + 1);
    used.assign(N + 1, false);

    Try(1); // Bắt đầu điền từ vị trí thứ 1

    return 0;
}
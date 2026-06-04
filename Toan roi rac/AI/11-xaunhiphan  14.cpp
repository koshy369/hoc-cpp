#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Tối ưu hóa nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, s;
    if (cin >> n >> s) {
        if (s > n || s < 0) {
            cout << 0 << "\n";
            return 0;
        }

        // Tạo bảng C[i][j] tương ứng với Tổ hợp chập j của i
        vector<vector<long long>> C(n + 1, vector<long long>(n + 1, 0));

        // Khởi tạo các giá trị cơ sở và tính toán theo công thức Pascal
        for (int i = 0; i <= n; ++i) {
            C[i][0] = 1; // C(i, 0) luôn bằng 1
            for (int j = 1; j <= i; ++j) {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }

        // Kết quả bài toán chính là C(n, s)
        cout << C[n][s] << "\n";
    }
    return 0;
}
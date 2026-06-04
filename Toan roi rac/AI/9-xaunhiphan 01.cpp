#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    // Tối ưu nhập xuất
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        // Sử dụng mảng dp kiểu long long để tránh tràn số
        vector<long long> dp(n + 1, 0);

        // Khởi tạo các giá trị cơ sở ban đầu cho i < k
        dp[0] = 1;
        for (int i = 1; i < k; ++i) {
            dp[i] = (1LL << i); // Tương đương với 2^i
        }

        // Áp dụng công thức quy hoạch động từ k đến n
        for (int i = k; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i] += dp[i - j];
            }
        }

        // In ra kết quả cho xâu độ dài n
        cout << dp[n] << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    if (cin >> n >> k) {
        // dp[i] lưu số lượng xâu độ dài i KHÔNG chứa k chữ số 1 liên tiếp
        vector<long long> dp(n + 1, 0);

        // Khởi tạo các giá trị cơ sở
        dp[0] = 1;
        for (int i = 1; i < k; ++i) {
            dp[i] = (1LL << i); 
        }

        // Tính toán quy hoạch động
        for (int i = k; i <= n; ++i) {
            for (int j = 1; j <= k; ++j) {
                dp[i] += dp[i - j];
            }
        }

        // Tổng số xâu nhị phân độ dài n là 2^n
        long long total_strings = (1LL << n);

        // Kết quả = Tổng số xâu - Số xâu không thỏa mãn
        long long ans = total_strings - dp[n];

        cout << ans << "\n";
    }
    return 0;
}
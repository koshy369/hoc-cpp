#include <iostream>

using namespace std;

void solve() {
    int n, p;
    cin >> n >> p;
    
    int count = 0;
    // Áp dụng định lý Legendre bằng cách chia liên tiếp
    while (n > 0) {
        count += n / p;
        n /= p;
    }
    
    cout << count << "\n";
}

int main() {
    // Tối ưu hóa I/O cho C++
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
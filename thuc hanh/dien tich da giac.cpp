#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>

using namespace std;

// Cấu trúc lưu tọa độ điểm
struct Point {
    double x, y;
};

void solve() {
    int n;
    cin >> n;
    
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y;
    }
    
    double area = 0;
    
    // Áp dụng công thức Shoelace
    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n; // Đỉnh kế tiếp, nếu là đỉnh cuối thì nối về đỉnh 0
        area += (p[i].x * p[next].y) - (p[next].x * p[i].y);
    }
    
    // Lấy giá trị tuyệt đối và chia 2
    area = abs(area) / 2.0;
    
    // In kết quả với 3 chữ số thập phân
    cout << fixed << setprecision(3) << area << "\n";
}

int main() {
    // Tối ưu tốc độ I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sinh cấu hình chỉnh hợp chập k của n kế tiếp
bool next_chinh_hop(vector<int>& a, int n, int k) {
    // Mảng đánh dấu để quản lý các phần tử đã được sử dụng
    vector<bool> used(n + 1, false);
    
    // Tiến trình duyệt ngược từ vị trí cuối cùng lên đầu
    for (int i = k - 1; i >= 0; --i) {
        
        // Bước 1: Khôi phục lại trạng thái các số đã bị chiếm bởi phần tiền tố (từ vị trí 0 đến i-1)
        fill(used.begin(), used.end(), false);
        for (int j = 0; j < i; ++j) {
            used[a[j]] = true;
        }
        
        // Bước 2: Tìm số nhỏ nhất lớn hơn a[i] mà chưa bị chiếm(chay tu so =a[i]+1 den n)
        int next_val = -1;
        for (int val = a[i] + 1; val <= n; ++val) {
            if (!used[val]) {// chua dung=> danh dau
                next_val = val;
                break;
            }
        }
        
        // Nếu tìm thấy, tiến hành cập nhật cấu hình mới=> XONG
        if (next_val != -1) {
            a[i] = next_val;
            used[next_val] = true; // Đánh dấu số vừa chọn là đã dùng
            
            // Bước 3: Điền các vị trí còn lại (từ i+1 đến k-1) bằng các số nhỏ nhất chưa dùng
            int current_fill = 1;
            for (int j = i + 1; j < k; ++j) {
                while (used[current_fill]) {
                    current_fill++; // Bỏ qua nếu số này đã bị sử dụng
                }
                a[j] = current_fill;
                used[current_fill] = true;
            }
            return true; // Sinh thành công cấu hình kế tiếp
        }
    }
    return false; // Đã đạt đến cấu hình cuối cùng (ví dụ: 5 4 3)
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> a (k);
    for (int i=0; i<k; i++){
        cin>>a[i];
    }

    cout << "Cau hinh ban dau: ";
    for (int x : a) cout << x << " ";
    cout << "\n";

    if (next_chinh_hop(a, n, k)) {
        cout << "Cau hinh ke tiep: ";
        for (int x : a) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Day da la cau hinh cuoi cung!\n";
    }

    return 0;
}
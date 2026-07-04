#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sinh cấu hình tổ hợp chập k của n kế tiếp
// neu cuoi la 789 thi dau la 123, vs k=3 n=9
//-> o vi tri a[i] thi a[i]max= n-k+i+1
bool next_to_hop(vector<int>& a, int n, int k) {
    // Tiến trình duyệt ngược từ vị trí cuối cùng lên đầu
    for (int i = k - 1; i >= 0; --i) {
        
        if(a[i]!= n-k+i+1){//chua max
            a[i]++;
            //vi a[i] nên dãy sau a phải là dãy tăng dần nhỏ nhất, vdu: a[i]=3 thi  4 5 6 .... den khi lap day
            int current_fill = a[i];
            for (int j = i + 1; j < k; ++j) { 
                a[j] = ++ current_fill;            }
            return true; // Sinh thành công cấu hình kế tiếp
        }
    }
    return false; // Đã đạt đến cấu hình cuối cùng (ví dụ: 3 4 5)
}

int main() {
    int n, k;
    cin>>n>>k;
    vector<int> a (k);
    for (int i=0; i<k; i++){
        cin>>a[i];
    }
    if (next_to_hop(a, n, k)) {
        cout << "Cau hinh ke tiep: ";
        for (int x : a) cout << x << " ";
        cout << "\n";
    } else {
        cout << "Day da la cau hinh cuoi cung!\n";
    }

    return 0;
}
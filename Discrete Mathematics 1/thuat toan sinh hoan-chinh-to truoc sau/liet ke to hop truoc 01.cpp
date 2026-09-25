#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Hàm sinh cấu hình tổ hợp chập k của n kế tiếp
// neu cuoi la 789 thi dau la 123, vs k=3 n=9
//-> o vi tri a[i] thi a[i]min= i +1, a[i]max= n-k+i+1

bool next_to_hop(vector<int>& a, int n, int k) {
    // vidu 12456 với n=7 => cau hinh truoc la 12367

    // Tiến trình duyệt ngược từ vị trí cuối cùng lên đầu
    for (int i = k - 1; i >= 0; --i) {

        int min_val = (i > 0) ? a[i-1] + 1 : 1; //k the be hon cai truoc
        
        if (a[i] > min_val) {
            a[i]--;
            //vì a[i] đổi nên dãy sau a[i] phải là dãy tăng dần lớn nhất
            int current_fill = n;
            for (int j = k-1; j >i; --j) { 
                a[j] = current_fill --;            }
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
        //in Cau hinh lien truoc:
        for (int x : a) cout << x << " ";
        cout << "\n";
    } else {
        cout << "0\n";
    }

    return 0;
}
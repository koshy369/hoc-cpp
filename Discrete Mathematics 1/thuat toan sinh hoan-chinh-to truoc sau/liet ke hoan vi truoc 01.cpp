#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/* 
Mục tiêu: Tìm cấu hình hoán vị ngay ĐỨNG TRƯỚC cấu hình hiện tại.
Ví dụ: 1 2 3 5 4  => 1 2 3 4 5
vs n=5 Cấu hình đầu tiên là 1 2 3 4 5 (không có cấu hình trước).
Cấu hình sau luôn LỚN hơn cấu hình trước, nên cấu hình trước phải NHỎ hơn.
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    // vd 3 2 1 4 5

    // Tìm vị trí i ĐẦU TIÊN từ phải sang trái sao cho a[i] > a[i+1] 
    // (Tìm đoạn đang tăng dần từ trái sang phải để phá vỡ nó)
    int i = n - 2;
    while (i >= 0 && a[i] <= a[i + 1]) {
        i--;
        }//-> thay a[i] =2, i=1

    // Nếu i < 0, đây là cấu hình đầu tiên (ví dụ 1 2 3 4 5), không có cấu hình trước
    if (i < 0) {
        cout << "0" << endl;
        return;
    }
    // Bước 2: Tìm số a[j] LỚN NHẤT trong các số bên phải a[i] mà vẫn NHỎ HƠN a[i](chac chan se thay)
    int j = n - 1;
    while (a[j] >= a[i]) {
        j--;
    }//-> thay a[j]=1, j=2

    // Bước 3: Đổi chỗ a[i] và a[j]
    swap(a[i], a[j]);
    //=> 3 1 2 4 5

    // Bước 4: Lật ngược đoạn từ i + 1 đến cuối dãy 
    // Vì sau khi swap, đoạn sau đang tăng dần, lật ngược lại để nó thành lớn nhất có thể(giảm dần)
    
    reverse(a.begin() + i + 1, a.end()); //3 1 5 4 2

    // In kết quả
    for (int k = 0; k < n; k++) {
        cout << a[k] << " ";
    }
    cout << endl;
}

int main() {
    solve();
    return 0;
}
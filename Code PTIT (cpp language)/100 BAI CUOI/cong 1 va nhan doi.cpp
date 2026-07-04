#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define vll vector<long long>

ll n, tong;
vll a;

void in(){
    cin >> n;
    tong = 0; // Khởi tạo lại biến tổng cho mỗi bộ test
    a.resize(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void solve(){
    ll max_nhan_doi = 0; // Lưu số lần nhân đôi nhiều nhất của một phần tử
    ll tong_cong_1 = 0;  // Lưu tổng số lần cộng 1 của tất cả phần tử

    for (int i = 0; i < n; i++) {
        ll val = a[i];
        if (val == 0) continue;

        ll dem_nhan_doi = 0;
        while (val > 0) {
            if (val % 2 != 0) {
                tong_cong_1++; // Nếu là số lẻ, cần 1 phép cộng 1
                val--;
            } else {
                dem_nhan_doi++; // Nếu là số chẵn, cần 1 phép nhân đôi
                val /= 2;
            }
        }
        // Số lần nhân đôi chung của cả mảng bằng số lần nhân đôi lớn nhất của 1 phần tử
        max_nhan_doi = max(max_nhan_doi, dem_nhan_doi);
    }

    // Kết quả cuối cùng là tổng của hai loại thao tác
    tong = tong_cong_1 + max_nhan_doi;
}

void out(){
    cout << tong << "\n";
}

int main(){
    
    int test;
    cin >> test;
    while (test--){
        in(); 
        solve(); 
        out();
    }
    return 0;
}
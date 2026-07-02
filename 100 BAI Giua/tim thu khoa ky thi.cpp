#include <bits/stdc++.h>

using namespace std;

struct ThiSinh {
    int ma;
    string ten, ngaySinh;
    double d1, d2, d3, tong;
};

int main() {
    int n;
    cin >> n;
    vector<ThiSinh> ds(n);
    double maxD = -1.0;

    for (int i = 0; i < n; i++) {
        ds[i].ma = i + 1;
        cin.ignore();
        getline(cin, ds[i].ten);
        getline(cin, ds[i].ngaySinh);
        cin >> ds[i].d1 >> ds[i].d2 >> ds[i].d3;
        ds[i].tong = ds[i].d1 + ds[i].d2 + ds[i].d3;
        if (ds[i].tong > maxD) {
            maxD = ds[i].tong;
        }
    }

    for (int i = 0; i < n; i++) {
        if (ds[i].tong == maxD) {
            cout << ds[i].ma << " " << ds[i].ten << " " << ds[i].ngaySinh << " ";
            cout << fixed << setprecision(1) << ds[i].tong << endl;
        }
    }

    return 0;
}
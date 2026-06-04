#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct DoanhNghiep {
    string ma, ten;
    int soLuong;
};

bool cmp(DoanhNghiep a, DoanhNghiep b) {
    if (a.soLuong != b.soLuong) {
        return a.soLuong > b.soLuong;
    }
    return a.ma < b.ma;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<DoanhNghiep> ds(n);
    for (int i = 0; i < n; i++) {
        scanf("\n");
        getline(cin, ds[i].ma);
        getline(cin, ds[i].ten);
        cin >> ds[i].soLuong;
    }

    sort(ds.begin(), ds.end(), cmp);

    for (int i = 0; i < n; i++) {
        cout << ds[i].ma << " " << ds[i].ten << " " << ds[i].soLuong << endl;
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct GiangVien {
    string ma, hoTen, ten, boMon;
};
string getTen(string s) {
    stringstream ss(s);
    string tmp, res;
    while (ss >> tmp) {
        res = tmp;
    }
    return res;
}
string rutGonBoMon(string s) {
    stringstream ss(s);
    string word, res = "";
    while (ss >> word) {
        res += toupper(word[0]);
    }
    return res;
}

bool cmp(GiangVien a, GiangVien b) {
    if (a.ten != b.ten) return a.ten < b.ten;
    return a.ma < b.ma;
}

int main() {
    int n;
    cin >> n;
    scanf("\n");

    vector<GiangVien> ds(n);
    for (int i = 0; i < n; i++) {
        // Tự động tạo mã GV
        string s_id = to_string(i + 1);
        while (s_id.length() < 2) s_id = "0" + s_id;
        ds[i].ma = "GV" + s_id;

        getline(cin, ds[i].hoTen);
        ds[i].ten = getTen(ds[i].hoTen);

        string mon;
        getline(cin, mon);
        ds[i].boMon = rutGonBoMon(mon);
    }

    sort(ds.begin(), ds.end(), cmp);

    for (auto x : ds) {
        cout << x.ma << " " << x.hoTen << " " << x.boMon << endl;
    }

    return 0;
}
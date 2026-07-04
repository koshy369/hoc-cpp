#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct GiangVien {
    string ma, hoTen, boMonGoc, boMonRutGon;
};

string rutGon(string s) {
    stringstream ss(s);
    string word, res = "";
    while (ss >> word) {
        res += toupper(word[0]);
    }
    return res;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    scanf("\n");

    vector<GiangVien> ds(n);
    for (int i = 0; i < n; i++) {
        string s_id = to_string(i + 1);
        if (s_id.length() < 2) s_id = "0" + s_id;
        ds[i].ma = "GV" + s_id;

        getline(cin, ds[i].hoTen);
        getline(cin, ds[i].boMonGoc);
        ds[i].boMonRutGon = rutGon(ds[i].boMonGoc);
    }

    int q;
    cin >> q;
    scanf("\n");
    while (q--) {
        string query;
        getline(cin, query);
        string queryRG = rutGon(query);
        cout << "DANH SACH GIANG VIEN BO MON " << queryRG << ":" << endl;
        for (int i = 0; i < n; i++) {
            if (ds[i].boMonRutGon == queryRG) {
                cout << ds[i].ma << " " << ds[i].hoTen << " " << ds[i].boMonRutGon << endl;
            }
        }
    }

    return 0;
}
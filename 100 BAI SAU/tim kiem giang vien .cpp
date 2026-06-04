#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

struct GiangVien {
    string ma, hoTen, boMon;
};

string rutGon(string s) {
    stringstream ss(s);
    string word, res = "";
    while (ss >> word) {
        res += toupper(word[0]);
    }
    return res;
}

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    scanf("\n");

    vector<GiangVien> ds(n);
    for (int i = 0; i < n; i++) {
        string s_id = to_string(i + 1);
        while (s_id.length() < 2) s_id = "0" + s_id;
        ds[i].ma = "GV" + s_id;

        getline(cin, ds[i].hoTen);
        string mon;
        getline(cin, mon);
        ds[i].boMon = rutGon(mon);
    }

    int q;
    cin >> q;
    scanf("\n");
    while (q--) {
        string key;
        getline(cin, key);
        cout << "DANH SACH GIANG VIEN THEO TU KHOA " << key << ":" << endl;
        
        string lowerKey = toLower(key);
        for (int i = 0; i < n; i++) {
            string lowerName = toLower(ds[i].hoTen);
            if (lowerName.find(lowerKey) != string::npos) {
                cout << ds[i].ma << " " << ds[i].hoTen << " " << ds[i].boMon << endl;
            }
        }
    }

    return 0;
}
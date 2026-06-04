#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == '\t') {
            s[i] = ' ';
        }
    }
    int dem = 0;
    stringstream ss(s);
    string token;
    while (ss >> token) {
        dem++;
    }
    cout << dem << endl;
}
int main() {
    int test;
    cin >> test;
    cin.ignore();
    while (test--) solve();
    return 0;
}
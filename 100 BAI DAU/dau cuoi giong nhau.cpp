#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void solve() {
    string input;
    if (!getline(cin, input)) return;

    map<char, long long> counts;
    // dem so luong moi loai ki tu
    for (char c : input) { 
        counts[c]++;
    }

    long long tong = 0;
    // Duyệt qua từng cặp {giá trị, số lần xuất hiện} trong map 'counts'
    for (auto const& [key, val] : counts) {
        tong += (val * (val - 1))/2; 
    }
    tong += input.length();

    cout << tong << endl;
}

int main() {
    int test;
    if (!(cin >> test)) return 0;
    cin.ignore();
    while (test--) {
        solve();
    }
    return 0;
}
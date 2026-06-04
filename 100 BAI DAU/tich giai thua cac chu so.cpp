#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    string a;
    cin >> n >> a;
    
    string result = "";
    for (char c : a) {
        if (c == '0' || c == '1') continue;
        
        if (c == '2') result += "2";
        else if (c == '3') result += "3";
        else if (c == '4') result += "322";
        else if (c == '5') result += "5";
        else if (c == '6') result += "53";
        else if (c == '7') result += "7";
        else if (c == '8') result += "7222";
        else if (c == '9') result += "7332";
    }
    sort(result.rbegin(), result.rend());
    cout << result << endl;
}

int main() {
    int test;
    if (!(cin >> test)) return 0;
    while (test--) {
        solve();
    }
    return 0;
}
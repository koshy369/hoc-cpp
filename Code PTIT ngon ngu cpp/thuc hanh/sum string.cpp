#include <bits/stdc++.h>
using namespace std;

string addStr(const string& a, const string& b) {
    string res = "";
    int carry = 0, i = a.size() - 1, j = b.size() - 1;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res += (char)('0' + sum % 10);
        carry = sum / 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool check(const string& S, int l1, int l2) {
    string a = S.substr(0, l1);
    string b = S.substr(l1, l2);
    if ((a.size() > 1 && a[0] == '0') || 
        (b.size() > 1 && b[0] == '0')) return false;
    
    int pos = l1 + l2;
    while (pos < (int)S.size()) {
        string c = addStr(a, b);
        int cl = c.size();
        if (pos + cl > (int)S.size()) return false;
        if (S.substr(pos, cl) != c) return false;
        pos += cl;
        a = b;
        b = c;
    }
    return pos == (int)S.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        int n = S.size();
        bool found = false;
        
        for (int l1 = 1; l1 < n && !found; l1++) {
            for (int l2 = 1; l1 + l2 < n && !found; l2++) {
                if (check(S, l1, l2)) found = true;
            }
        }
        
        cout << (found ? "Yes" : "No") << "\n";
    }
    return 0;
}
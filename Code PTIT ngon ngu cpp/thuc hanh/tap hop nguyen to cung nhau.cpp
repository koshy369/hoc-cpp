#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;

ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }

int main() {
    
    int T;
    cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        lll S = (lll)n * (n + 1) / 2;
        lll M = m;
        bool ok = false;
        if ((S - M) >= 0 && (S - M) % 2 == 0) {
            lll x = (S - M) / 2;
            if (x > 0 && x < S) {
                lll g = __gcd(x, S);
                if (g == 1) ok = true;
            }
        }
        if (!ok && (S + M) % 2 == 0) {
            lll x = (S + M) / 2;
            if (x > 0 && x < S) {
                lll g = __gcd(x, S);
                if (g == 1) ok = true;
            }
        }
        
        cout << (ok ? "Yes" : "No") << "\n";
    }
    return 0;
}
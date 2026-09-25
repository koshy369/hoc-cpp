#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

const ll MOD = 1e9 + 7;
ll solve(ll a, ll b) {
    ll r=1;
    a %= MOD;
    while (b>0) {
        if (b & 1) { //b%2!=0 (bit cuoi la le vdu 0001=>1 ma 0010 =2)
            r =(r * a) % MOD;
        }
        a=(a*a) % MOD;
        b>>=1; //b/=2
    }
    return r;
}

void solve() {
    ll a,b;
    while (cin>>a>>b) {
        if (a == 0 && b == 0) {
            break;
        }
        cout << solve(a, b) << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
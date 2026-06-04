#include <iostream>

using namespace std;
long long f[1005];
const long long MOD = 1e9 + 7;

void prepare() {
    f[0] = 0;
    f[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    }
}

void solve() {
    int n;
    if (!(cin >> n)) return;
    cout<<f[n]<<endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    prepare();
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
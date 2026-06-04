#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1e9 + 7;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res = (res * base) % MOD;
        }
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<long long> a(n);
    long long g = 0;
    long long h = 1;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        g = gcd(g, a[i]);
        h = (h * a[i]) % MOD;
    }

    cout << power(h, g) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
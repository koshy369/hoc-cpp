#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    while (b != 0) {
        long long r = a % b;
        a = b;
        b = r;
    }
    return a;
}

void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long g = 0;
    for (int i = 1; i < n; i++) {
        g = gcd(g, a[i] - a[i - 1]);
    }

    if (g == 0) {
        cout << 0 << "\n";
        return;
    }

    int count = 0;
    for (long long i = 1; i * i <= g; i++) {
        if (g % i == 0) {
            count++;
            if (i * i != g) {
                count++;
            }
        }
    }

    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
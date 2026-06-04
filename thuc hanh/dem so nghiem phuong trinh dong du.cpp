#include <iostream>
#include <vector>

using namespace std;

void solve() {
    long long b, p;
    cin >> b >> p;

    vector<long long> valid_x;
    for (long long i = 1; i <= p; i++) {
        if ((i * i) % p == 1) {
            valid_x.push_back(i);
        }
    }

    long long ans = 0;
    long long full_cycles = b / p;
    long long rem = b % p;

    for (long long x : valid_x) {
        ans += full_cycles;
        if (x <= rem) {
            ans++;
        }
    }

    cout << ans << "\n";
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
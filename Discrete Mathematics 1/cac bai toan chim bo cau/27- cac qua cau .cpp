#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long h, m, n, t;
    if (cin >> h >> m >> n >> t) {
        long long ans = (m * n) * (t - 1) + 1;
        
        if (ans > h) {
            cout << 0 << "\n";
        } else {
            cout << ans << "\n";
        }
    }
    return 0;
}
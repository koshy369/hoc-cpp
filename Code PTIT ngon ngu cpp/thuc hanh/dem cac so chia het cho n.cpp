#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    int m, n;
    cin >> m >> n;
    string s;
    cin >> s;
    vector<vector<long long>> dp(m, vector<long long>(n, 0));
    dp[0][(s[0] - '0') % n] = 1;
    for (int i = 1; i < m; i++) {
        int digit = s[i] - '0';
        for (int j = 0; j < n; j++) {
            dp[i][j] = dp[i - 1][j];
        }
        dp[i][digit % n]++;
        for (int j = 0; j < n; j++) {
            if (dp[i - 1][j] > 0) {
                int next_rem = (j * 10 + digit) % n;
                dp[i][next_rem] += dp[i - 1][j];
            }
        }
    }
    cout << dp[m - 1][0] << "\n";
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
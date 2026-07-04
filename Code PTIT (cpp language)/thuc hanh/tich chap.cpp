#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> h(3, vector<long long>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> h[i][j];
        }
    }

    long long total_sum = 0;

    for (int i = 1; i < n - 1; i++) {
        for (int j = 1; j < m - 1; j++) {
            long long current_val = 0;
            
            current_val += h[0][0] * a[i - 1][j - 1];
            current_val += h[0][1] * a[i - 1][j];
            current_val += h[0][2] * a[i - 1][j + 1];

            current_val += h[1][0] * a[i][j - 1];
            current_val += h[1][1] * a[i][j];
            current_val += h[1][2] * a[i][j + 1];

            current_val += h[2][0] * a[i + 1][j - 1];
            current_val += h[2][1] * a[i + 1][j];
            current_val += h[2][2] * a[i + 1][j + 1];

            total_sum += current_val;
        }
    }

    cout << total_sum << "\n";
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
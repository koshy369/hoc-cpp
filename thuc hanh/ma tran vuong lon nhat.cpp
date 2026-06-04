#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    if (!(cin >> n)) return;

    vector<vector<char>> a(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> hor(n, vector<int>(n, 0));
    vector<vector<int>> ver(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j >= 0; j--) {
            if (a[i][j] == 'X') {
                hor[i][j] = (j == n - 1) ? 1 : hor[i][j + 1] + 1;
            }
        }
    }

    for (int j = 0; j < n; j++) {
        for (int i = n - 1; i >= 0; i--) {
            if (a[i][j] == 'X') {
                ver[i][j] = (i == n - 1) ? 1 : ver[i + 1][j] + 1;
            }
        }
    }

    int max_side = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int max_possible = min(hor[i][j], ver[i][j]);
            
            for (int k = max_possible; k > max_side; k--) {
                if (hor[i + k - 1][j] >= k && ver[i][j + k - 1] >= k) {
                    max_side = k;
                    break;
                }
            }
        }
    }

    cout << max_side << "\n";
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
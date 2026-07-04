#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> rMax(n);
    rMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rMax[i] = max(a[i], rMax[i + 1]);
    }

    int i = 0, j = 0, max_dist = -1;
    while (i < n && j < n) {
        if (rMax[i] >= a[j]) {
            max_dist = max(max_dist, i - j);
            i++;
        } else {
            j++;
        }
    }

    cout << max_dist << "\n";
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
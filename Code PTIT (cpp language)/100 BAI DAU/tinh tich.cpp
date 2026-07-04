#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    if (!(cin >> test)) return 0;
    while (test--) {
        int n, m;
        cin >> n >> m;

        vector<long long> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<long long> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];

        long long ln = *max_element(a.begin(), a.end());
        long long nn = *min_element(b.begin(), b.end());

        cout << ln * nn << "\n"; 
    }
    return 0;
}
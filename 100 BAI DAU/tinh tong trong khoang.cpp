
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n,k; cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    while (k--) {
        int l,r; cin >> l >> r;
        long long sum = 0;
        for (int i = l-1; i < r; i++) {
            sum += a[i];
        }
        cout << sum <<endl;
    }
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
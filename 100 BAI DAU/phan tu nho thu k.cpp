
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n,k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[k-1] << endl;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
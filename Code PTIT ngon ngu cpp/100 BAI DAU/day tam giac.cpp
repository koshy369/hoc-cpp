
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    cout << a[n - 1] << endl;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
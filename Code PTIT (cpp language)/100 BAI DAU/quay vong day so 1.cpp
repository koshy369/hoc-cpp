
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    long d,n; cin >> n >> d;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = d; i < n; i++) {
        cout << a[i] << " ";
    }
    for (int i = 0; i < d; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
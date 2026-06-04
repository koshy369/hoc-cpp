
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int b[n],dem=0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    b[0]=a[0];
    cout << b[0] << " ";
    for (int i = 0; i < n; i++) {
        if (b[dem] != a[i]) {
            cout << a[i] << " ";
            dem++;
            b[dem]=a[i];
        }
    }
}

int main() {
	solve();
    return 0;
}
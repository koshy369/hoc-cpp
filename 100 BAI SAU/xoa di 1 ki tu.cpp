#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    string a;
    cin>>a;
    long long dem=1;
    long long results=0;
    for (int i = 1; i < n; i++) {
        if (a[i]==a[i-1]) {
            dem++;
        } else {
            results += ((dem-1) * dem) / 2;
            dem=1;
        }
    }
    results += ((dem-1) * dem) / 2;

    cout << results;

}

int main() {
    solve();
    return 0;
}
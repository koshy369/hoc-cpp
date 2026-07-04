
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    int b[n][2],dem=0;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    b[0][0]=a[0];
    b[0][1]=0;
    for (int i = 0; i < n; i++) {
        if (b[dem][0] != a[i]) {
            dem++;
            b[dem][0]=a[i];
            b[dem][1]=1;
        } else {
            b[dem][1]++;
        }
    }
    int dem1=0;
    for (int i = 0; i<= dem; i++) {
        if(b[i][1]>1){
            dem1+=b[i][1];
        }
    }
    cout << dem1 << endl;
}

int main() {
    int test;
    cin >> test;
	while (test--) solve();
    return 0;
}
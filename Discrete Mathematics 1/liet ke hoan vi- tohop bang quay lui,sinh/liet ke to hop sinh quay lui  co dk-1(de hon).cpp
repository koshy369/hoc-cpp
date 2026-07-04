#include <iostream>
#include <vector>
using namespace std;

int n, k, t;
int so1 = 0;
vector<int> a,X;

void xuat() {
    for (int i = 1; i <= n; i++) {
        if(a[i]) cout << X[i]<<" ";
    }
    cout << "\n";
}

void Try(int m) {
    if (m > n) {
        if (so1 == k) {
            int vi_tri_dau = -1;
            for (int i = 1; i <= n; i++) {
                if (a[i] == 1) {
                    vi_tri_dau = i;
                    break;
                }
            }
            if (vi_tri_dau == t) {
                xuat();
            }
        }
        return;
    }

    for (int i = 1; i >= 0; i--) {
        a[m] = i;
        if (i == 1) so1++;
        Try(m + 1);
        if (i) so1--; 
    }
}

void solve() {
    if (!(cin >> n >> k >> t)) return;
    a.resize(n + 1, 0);
    X.resize(n + 1);
    for(int i=1; i<=n;i++) X[i]=i;
    Try(1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    return 0;
}
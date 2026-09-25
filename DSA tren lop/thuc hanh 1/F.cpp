#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

int n,k,t;
vector<int> a;
int solve(int start, int r) {
    if (r== 1) {
        int summ = 0;
        for (int i = start; i<n; i++) {
            summ += a[i];
        }
        return (summ == t) ? 1 : 0;
    }
    int w=0;
    int summ=0;
    
    for (int i=start; i<=n-r; i++) {
        summ += a[i];
        if (summ == t) {
            w += solve(i + 1, r - 1);
        }
    }
    
    return w;
}

int main() {
    boost;
    cin>>n>>k;
    a.resize(n);
    int sum = 0;
    for (int i=0; i<n; ++i) {
        cin >> a[i];
        sum += a[i];
    }

    if (sum %k != 0) {
        cout<<0<<"\n";
        return 0;
    }

    t = sum / k;
    cout<< solve(0, k)<<"\n";
    return 0;
}
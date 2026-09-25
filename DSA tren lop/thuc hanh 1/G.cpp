#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

char solve(int n, ll k) {
    ll mid = 1LL << (n - 1); // 2 mu n-1

    if (k == mid) return(char)('A'+ n-1);

    else if (k < mid)  return solve(n-1, k);

    else  return solve(n-1, k-mid);
}

int main() {
    boost;
    int t;
    cin>>t;
    while (t--) {
        int n;
        ll k;
        cin>>n>>k;
        cout<< solve(n, k)<< "\n";
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<ll>a,b;
int n,m;

void solve() {
    cin>>n>>m;
    a.resize(n,0);
    int luu=-1;
    for(int i=0; i<n; i++){
        cin>>a[i];
        if(a[i]==m) luu = 1;
    }
    cout<<luu<<"\n";
}

int main() {
    boost;
    int t; cin>>t;
    while(t--)   solve();
    
    return 0;
}
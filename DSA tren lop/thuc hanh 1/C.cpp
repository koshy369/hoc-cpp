#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
set<ll> b;
vector<ll> c;
void solve(){
    cin>>n>>m;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());

    ll sum = 0;

    for(int i=0; i<n;i++){
        auto it = lower_bound(a.begin() + i + 1, a.end(), a[i] + m);
        sum += distance(a.begin() + i + 1, it);
    }
    cout<<sum<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


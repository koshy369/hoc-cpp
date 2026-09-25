#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
void solve(){
    ll sum=0;
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    for(int i; i<n; i++){
        sum= (sum+i*a[i]) %((int)1e9 +7);
    }
    cout<<sum<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
void out(vector<ll> k){
    for( auto x: k){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void solve(){
    
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    out(a);
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


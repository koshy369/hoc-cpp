#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
void out(vector<ll> k){
    for( int i=0; i<m; i++){
        cout<<a[i]<<" ";
    }
    cout<<"\n";
}
bool ss(const int &x,const int &y){
    return x>y;
}
void solve(){
    
    cin>>n>>m;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end(),ss);
    out(a);
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


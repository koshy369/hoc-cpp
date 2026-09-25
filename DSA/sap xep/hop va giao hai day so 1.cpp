#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
set<ll>a,b, hop, giao;
set<ll> hop2th(set<ll> A,set<ll> B){
    set<ll> h;
    for(auto x: A){
        h.insert(x);
    }
    for(auto x: B){
        h.insert(x);
    }
    return h;
}
set<ll> giao2th(set<ll> A,set<ll> B){
    set<ll> g;
    for(auto x : B){
        if(A.find(x)!= A.end()){
            g.insert(x);
        }
    }
    return g;
}
void out(set<ll> k){
    for( auto x: k){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void solve(){
    a.clear();
    b.clear();
    hop.clear();
    giao.clear();
    cin>>n>>m;
    ll x;
    for(int i=0;i<n;i++){
        cin>>x;
        a.insert(x);
    }
    for(int i=0;i<m;i++){
        cin>>x;
        b.insert(x);
    }
    hop =hop2th(a,b);
    giao= giao2th(a,b);
    out(hop);
    out(giao);
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


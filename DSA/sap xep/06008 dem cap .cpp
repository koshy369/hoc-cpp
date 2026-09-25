#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<ll>a,b;
int n,m;

void solve() {
    cin>>n>>m;
    a.resize(n,0);
    b.resize(m,0);
    int dem=0;
    for(auto &x: a){
        cin>>x;
    }
    for(auto &y: b){
        cin>>y;
    }
    for(auto &x: a){
        for(auto &y: b){
            if(x==1 && y>1) dem++;
            else if(x==2 &y==3) dem++;
            else if(x>y) dem++;
        }
    }
    cout<<dem<<"\n";
}

int main() {
    boost;
    int t; cin>>t;
    while(t--)   solve();
    
    return 0;
}
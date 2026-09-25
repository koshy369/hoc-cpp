#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

ll maxn = 1e8 +7;
int n,m,sum,ok=0;
vector<ll>a,b;

void out(vector<ll> k){
    for(auto x: k){
        cout<<x<<" ";
    }
    cout<<"\n";
}
bool ss(const int &x,const int &y){
    return x>y;
}
void solve(){
    
    cin>>n>>m;
    b.assign(m+n,0);
    for(int i=0;i< m+n;i++){
        cin>>b[i];
    }
    sort(b.begin(), b.end());
    out(b);
    
}

int main(){
    boost
    int t; cin>>t;
    while(t--)  solve();
}


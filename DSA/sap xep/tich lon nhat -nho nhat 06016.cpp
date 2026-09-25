#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

ll maxn = 1e8 +7;
int n,m,sum,ok=0;
vector<ll>a,b;

void out(vector<ll> k){
    int ks = k.size();
    for( int i=0; i< ks; i++){
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
    b.assign(m,0);
    for(int i=0; i<n ; i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b.begin(), b.end());
    sort(a.begin(), a.end(),ss);
    cout <<a[0]*b[0] << "\n";
    
}

int main(){
    boost
    int t; cin>>t;
    while(t--)  solve();
}


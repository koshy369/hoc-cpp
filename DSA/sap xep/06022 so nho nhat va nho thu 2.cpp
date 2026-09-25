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
    unordered_set<ll> c;
    cin>>n;
    for(int i=0; i<n ; i++){
        ll x;
        cin >> x;
        c.insert(x);
    }
    a.assign(c.begin(), c.end());
    sort(a.begin(), a.end());
    ll s=a.size();
    if(s < 2) cout<<"-1"<<"\n";
    else cout << a[0] << " " << a[1]<< "\n";
}

int main(){
    boost
    int t; cin>>t;
    while(t--)  solve();
}


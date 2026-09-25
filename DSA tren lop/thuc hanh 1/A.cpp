#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<string>a;
set<ll> b;
vector<ll> c;
void solve(){
    cin>>n;
    a.assign(n,"");
    b.clear();
    c.clear();
    for(int i=0;i<n;i++){
        cin>>a[i];
        int len= (int)a[i].length();
        for(int j=0; j<len; j++){
            b.insert(a[i][j]);
        }
    }
    c.assign(b.begin(), b.end());
    reverse(c.begin(), c.end());

    for(auto x: c){
        cout<<x-'0'<<" ";
    }
    
    cout<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


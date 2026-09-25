#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);

using namespace std;
#define ll long long
#define vll vector<long long>

struct So{
    int s, xh;
};
ll n,m,k,t;
vll a;
bool ssanh(const So &x,const So &y){
    if(x.xh == y.xh) return x.s < y.s;
    return x.xh > y.xh;
}
void solve(){
    cin >> n ;
    map<int,int> b;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(b.find(x)!= b.end()){
            b[x]++;
        }
        else b[x]=1;
    }
    vector<So> c;
    for(auto [key,val] : b){
        c.push_back({key,val});
    }
    sort(c.begin(), c.end(), ssanh);
    for(auto x : c){
        for(int i=0; i<x.xh ; i++){
            cout<<x.s<<" ";
        }
    }
    cout<<"\n";

    
}
int main()
{
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define boost  ios_base::sync_with_stdio(false); cin.tie(NULL);
vector<ll>a,b;
int n,m;
void out(int k){
    cout<<"Buoc "<<k<<": ";
    for(auto x :a){
        cout<<x<<" ";
    }
    cout<<"\n";
}
void solve() {
    cin>>n;
    a.resize(n,0);
    int count=0;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    for(int i=0; i<n - 1; i++){
        for(int j=i+1; j<n; j++){
            if(a[j]<a[i]) swap(a[i], a[j]);
        }
        out(++count);
    }
    
}

int main() {
    boost;
    solve();
    
    return 0;
}
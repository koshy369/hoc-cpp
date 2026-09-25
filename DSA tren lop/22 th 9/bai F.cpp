#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a,b;

void solve(){
    ll sum=0;
    cin>>n;
    a.assign(n+1,0);
    b=a;
    ll maxV= 0;
    for (int i = n-1; i>=0; i--) {
        int x; cin>>x;
        a[x]= a[x-1]+1;
        maxV=max(maxV,a[x]);
    }
    cout<<n-maxV<<endl;

}

int main(){
    solve();
}


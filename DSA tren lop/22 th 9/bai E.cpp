#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;

void solve(){
    ll sum=0;
    cin>>n;
    a.assign(n,0);
    for (int i = n-1; i>=0; i--) {
        cin>>a[i];
        if (a[i]>0) sum+=a[i]*2;
    }
    cout<<sum<<endl;

}

int main(){
    solve();
}


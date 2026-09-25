#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;

void solve(){
    ll sum=0;
    cin>>m>>n;
    a.assign(n,0);
    
    if ((m==0 && n>1) || m>9*n) {
        cout<< -1<< "\n";
        return;
    }
    if (n==1 && m==0) {
        cout<<0<< "\n";
        return;
    }
    m -= 1;
    for (int i = n-1; i>0; i--) {
        if (m > 9) {
            a[i] = 9;
            m-=9;
        } else {
            a[i] = m;
            m=0;
        }
    }
    a[0] = m + 1;
    for(auto x: a){
        cout<<x;
    }
    cout<<endl;

}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a;
void solve(){
    ll sum=0;
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(), a.end());
    ll so1=0,so2=0;
    for(int i=0; i<n; i+=2){
         so1= so1*10 +a[i];
         if(i+1<n){
            so2= so2*10 +a[i+1];
        }
    }
    cout<<so1+so2<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


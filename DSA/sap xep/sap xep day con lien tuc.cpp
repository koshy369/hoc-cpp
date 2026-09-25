#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;
vector<ll>a,b;
void solve(){
    
    cin>>n;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    b=a;
    int first, last;
    sort(a.begin(), a.end());
    int f=-1,l=-1;
    for(int i=0; i<n;i++){
        if(a[i]!= b[i]){
            f=i+1;
            break;
        }
    }
    for(int i=n-1; i>=0;i--){
        if(a[i]!= b[i]){
            l=i+1;
            break;
        }
    }
    cout<<f<<" "<<l<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


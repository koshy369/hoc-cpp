#include <bits/stdc++.h>
using namespace std;

int n,m,sum,ok=0;
string a;

bool sinh(int p) {
    int q=-1;
    int max=0;
    for(int i=p+1; i<n; i++){
        if(a[i]>a[p] && a[i]>= max){
            q=i;
            max=a[i];
        }
    }
    if(q==-1) return 0;
    swap(a[p],a[q]);
    return 1;
}
void solve(){
    cin>>m;
    cin>>a;
    n=(int)a.length();
    for(int i=0;i<n-1 && m>0;i++){
        if(sinh(i)){
            m--;
        }
    }
    cout<<a;
    cout<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


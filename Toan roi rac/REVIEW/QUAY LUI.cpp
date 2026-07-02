#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void in(){
    for( auto i:a){
        cout<<i<<" ";
    }
    cout<<endl;
}

void Try(int i){
    if(i==n){
        in();
        return;
    }
    for(int j=0;j<=1;j++){
        a[i]=j;
        Try(i+1);
    }
}

void solve(){
    a.assign(n+1,0);
    Try(1);
}
int main(){
    solve();
}
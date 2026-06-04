#include <bits/stdc++.h>
using namespace std;
int a[100],n;

void xuat(){
    for(int i=0;i<n;i++){
        cout <<a[i];
    }
    cout<<endl;
}

void Try(int m){
    for(int i=0;i<2;i++){
        a[m]=i;
        if(m == n-1) xuat();
        else Try(m+1);
    }
}

void solve(){
    cin>>n;
    Try(0);
}
int main(){
    solve();
}
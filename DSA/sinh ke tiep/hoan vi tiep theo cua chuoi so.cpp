#include <bits/stdc++.h>

using namespace std;
void solve() {
    string a;
    int m,n;

    cin>>m>>a;
    n=(int)a.length();
    int i=-1,j;

    cout<<m<<" ";
    for (i=n-2; i>=0 ;i-- ){
        if(a[i]<a[i+1]){
            break;
        }
    }
    if(i< 0){
        cout<<"BIGGEST"<<"\n";
        return;
    }
    int min=n-1;
    int minn=1000000;
    for (j=n-1; j>i ;j-- ){
        if(a[j] <minn && a[j]> a[i]){
            min= j;
            minn=a[j];
        }
    }
    swap(a[i],a[min]);// doi cho
    
    reverse(a.begin() + i + 1 , a.end());
    for(auto x : a){
        cout<<x;
    }    cout<<"\n";
} 

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    
}
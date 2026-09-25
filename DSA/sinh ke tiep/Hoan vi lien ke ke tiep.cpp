#include <bits/stdc++.h>

using namespace std;
void solve() {

    int n;
    cin>>n;
    int a[n];
    for (int i=0;i<n ;i++ ){
        cin>>a[i];
    }

    int i=-1,j;
    for (i=n-2; i>=0 ;i-- ){
        if(a[i]<a[i+1]){
            break;
        }
    }
    if(i< 0){
        for (int i=1; i<=n; i++) cout << i << " ";
        cout<<endl;
    }
    int min=n-1;
    for (j=n-1; j>i ;j-- ){
        if(a[j] <min && a[j]> a[i]){
            min= j;
        }
    }
    
    swap(a[i],a[min]);// doi cho
    
    
    reverse(a + i + 1, a + n);
    
    for (int k=0; k<n;k++ )
        cout<< a[k]<<" ";
    cout<< endl;
}

int main() {
    int t; cin>>t;
    while(t--){
        solve();
    }
    
}
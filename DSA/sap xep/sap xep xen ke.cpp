#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int n,m;
vi a;
int main(){
    ios::sync_with_stdio(false);
    cin>>m;
    while(m--){
        cin>>n;
        a.assign(n+1,0);
        for(int i=1;i<n+1;i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        int mid = n/2;
        for(int i=1; i<=mid ; i++){
            cout<<a[n-i+1]<<" "<<a[i]<<" ";
        }
        if (n%2!=0) cout<<a[n/2 + 1];
        cout<<endl;
    }
}// 1 2 3 4 5 6 7 => 7 1 6 2 5 3 4 =>1-> 4i<=(n)/2, khi i=n/2 thig chir in 1 cai
// 1 2 3 4 5 6=> 6 1 5 2 4 3=> i<=n/2, khi 
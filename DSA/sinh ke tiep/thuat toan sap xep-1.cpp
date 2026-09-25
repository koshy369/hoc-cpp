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
        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(), a.end());
        for(auto x : a){
                cout<<x<<" ";
        }
        cout<<endl;
    }
}
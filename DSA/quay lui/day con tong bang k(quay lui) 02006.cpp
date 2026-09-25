#include <bits/stdc++.h>
using namespace std;

int n,m,sum,ok=0;
vector<int> a;
vector<int> x;
void Try(int k){
    if (k==n){

        if(sum==m){
            ok=1;
            vector<int> b;
            for(int i=0; i<n; i++){
                if(x[i]==1) b.push_back(a[i]);
            }
            cout<<"[";
            size_t n1=b.size();
            for(size_t i=0; i< n1; i++){
                cout<<b[i]<<((i != n1 -1) ? " ": "] ");
            }
        }
        return;
    }
    for(int i=1; i>=0; i--){
        x[k]=i;

        sum+=a[k]*i;
        
        Try(k+1);

        sum-=a[k]*i;
    }
}

void solve(){
    cin>>n>>m;
    sum=0;ok=0;
    a.assign(n,0);
    x.assign(n,0);
    for (int &x : a){
        cin>>x;
    }
    sort(a.begin(), a.end());
    Try(0);
    if(!ok) cout<<"-1";
    cout<<"\n";

}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


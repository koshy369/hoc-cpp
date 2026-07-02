#include <bits/stdc++.h>

using namespace std;

int n,k;
vector<int> a;

void in(){
    for(int i=1;i<=k;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int i,int start_Val){
    for(int j=start_Val;j<=n;j++){
        a[i]=j;
        if (i==k) in();
        else Try(i+1,j+1);
    }
}
void solve(){
    cin>>n>>k;
    a.resize(k+1);
    Try(1,1);
}
int main(){
    solve();
}
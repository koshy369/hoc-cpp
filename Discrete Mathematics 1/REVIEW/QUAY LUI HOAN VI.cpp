#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a,usedV;
vector<int> UfixV;

void in(){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void Try(int i){
    for(int j=1;j<=n;j++){
        if (usedV[j] == false){
            a[i]=j;
            usedV[j]= true;

            if (i==n) in();
            else Try(i+1);

            usedV[j] = false;
        }
    }
}

void solve(){
    int k,yas=1;
    cin>>n>>k;
    a.resize(n+1);
    usedV.assign(n+1,0);
    Try(1);
}
int main(){
    solve();
}
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
    if(UfixV[i]){
        if(i==n) in();
        else Try(i+1);
        return;
    }
    
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
    UfixV.assign(n+1,0);
    usedV.assign(n+1,0);
    for(int i=0;i<=n;i++){
        a[i]=i;
    }
    for(int i=0;i<k;i++){
        //vị trí u của hoán vị là số v( a[u]=v )
        //->Cần đánh dấu vị trí u dat gia tri gi used chưa và giá trị của v dat vi tri nao?
        // -> neu nhap trung lap ca v va u thi van chap nhan
        int u,v;
        cin>>u>>v;
        if( (UfixV[u]==v || UfixV[u]==0 ) && ( usedV[v]==u || usedV[v]== 0)){
            a[u]=v;
            usedV[v]=u;
            UfixV[u]=v;
        }
        else yas=0;
    }
    if (yas) Try(1);
    else cout<<"0"<<endl;
}
int main(){
    solve();
}
#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int n,m,c,b,d,e,f, ok=0;
vi a;

void Try(int x,int z){
    if(x==z){
        ok=1;
    }
    if(x%3==0){
        int x1 = x*2/3 ,x2=x/3;
        if(x1>=z) Try(x1,z);
        if(x2>=z) Try(x2,z);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>c;
    while(c--){
        ok=0;
        cin>>n>>m;
        Try(n,m);
        if(ok) cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    }
}
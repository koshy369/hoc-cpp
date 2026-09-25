#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
typedef struct N{
    int f,o,av;// first place;origin value, absolute value
}N;
int n,m,b,c;
vector<N> a;
bool compare_nl(const N &a , const N &b){
    if(a.av==b.av) return a.f<b.f;
    return a.av <b.av;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>m;
    while(m--){
        cin>>n>>c;
        a.resize(n);
        for(int i=0;i<n;i++){
            cin>>a[i].o;
            a[i].av=abs(c-a[i].o);
            a[i].f=i;
        }
        sort(a.begin(), a.end(),compare_nl);
        for(int i=0; i<n ; i++){
            cout<<a[i].o<<" ";
        }
        cout<<endl;
    }
}
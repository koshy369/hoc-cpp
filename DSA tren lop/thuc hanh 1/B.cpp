#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,sum,ok=0;

typedef struct So{
    int stt;
    int x;
    int g;
}So;

vector<So> a;
set<ll> b;
vector<ll> c;


bool comparee(const So &a,const So &b){
    if(a.g== b.g) return a.stt<b.stt;
    return a.g<b.g;
}
void solve(){
    
    cin>>n>>m;
    a.resize(n);
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        a[i].stt=i;
        a[i].x=c;
        a[i].g= abs(m-c);
    }
    sort(a.begin(), a.end(),comparee);

    for(auto y: a){
        cout<<y.x<<" ";
    }
    
    cout<<"\n";
}

int main(){
    int t; cin>>t;
    while(t--)  solve();
}


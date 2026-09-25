#include<iostream>
#include <map>
#include <vector>

using namespace std;
#define ll long long
#define vll vector<long long>

ll n,m,k,t;
vll a;

void solve(){
    cin >> n >> m;
    map<int,int> b;
    for(int i=0; i<n; i++){
        int x; cin>>x;
        if(b.find(x)!= b.end()){
            b[x]++;
        }
        else b[x]=1;
    }
    if(b.find(m)!= b.end()){
        cout<<b[m]<< endl;
    }
    else cout<<-1<<endl;
}
int main()
{
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
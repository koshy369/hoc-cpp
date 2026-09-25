#include<iostream>
#include <map>
#include <vector>

using namespace std;
#define ll long long
#define vll vector<long long>
#define maxn 1000007

ll n,m,k,t;
vll a(maxn,1),c;
void tienxuly(){
    a[0]=a[1]=0;
    for(int i=2; i<maxn ; i++){
        if(a[i]==1){
            for(int j=i*2; j<maxn ; j+=i){
                a[j]=0;
            }
        }
    }
    for(int i=2; i<maxn ; i++){
        if(a[i]) c.push_back(i);
    }
}
void solve() {
    cin >> n;
    ll last = -1;
    ll first = -1;
    int ok=0;
    for(int i = 0; i < k && c[i] <= n/2 ; i++){
         ll l = n - c[i];
         if(a[l]){
             ok = 1;
             last = l;
             first = c[i];
             break;
         }
    }
    if (ok) cout<<first<<" "<<last<<"\n";
    else cout<<"-1"<<endl;
}
int main()
{
    tienxuly();
    k = c.size();
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
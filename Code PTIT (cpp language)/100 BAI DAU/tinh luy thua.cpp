#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
void solve() {
    ll x, y, p, d=1;
    cin>>x >>y >>p;
    x=x%p;
    while(y>0){
        if(y%2==1){
            d=(ll)((__int128)d*x)%p;
        }
        y = y>>1;
        x=(ll)((__int128)x*x)%p;
        
    }
    cout<<d <<endl;
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    if (!(cin >> test)) return 0;
    while (test--) {
        solve();
    }
    return 0;
}
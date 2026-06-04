#include <iostream>
#include <fstream>

using namespace std;
typedef long long ll;
void solve() {
    int n;
    cin>>n;
    ll a[n];
    for (int i=0 ; i<n; i++){
        cin>>a[i];
    }
    ll tong=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            tong+=abs(a[i]-a[j]);
        }
    }
    cout<<tong<<endl;

}
int main() {
    ios_base::sync_with_stdio(false);
    int test;
    if (!(cin >> test)) return 0;
    while (test--) {
        solve();
    }
    return 0;
}
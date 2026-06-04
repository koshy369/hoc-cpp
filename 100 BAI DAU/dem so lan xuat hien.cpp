#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void solve() {
    int n,k;
    cin >> n>>k;
    
    int dem=0;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i]==k) dem++;
    }
    if(dem>0) cout << dem << endl;
    else cout<<"-1"<<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
void solve() {
    int n,k;
    cin >> n>>k;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    for (int i=n-1;i>=n-k;i--){
        cout<<a[i]<<" ";
    }
    cout << endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
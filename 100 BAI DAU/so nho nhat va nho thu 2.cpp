
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    long long nho2=-1;
    
    for(int i = 1; i < n; i++){
        if(a[i]>a[0]) {
            nho2=a[i];
            break;
        }
    }
    if(nho2!=-1) cout<< a[0]<<" "<< nho2 <<endl;
    else cout<< -1<<endl;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
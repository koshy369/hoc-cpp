#include <iostream>
#include <vector>
#include <climits>
#include <cmath>
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long min_sum = LLONG_MAX;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            long long current_sum = a[i] + a[j];
            if (abs(current_sum) < abs(min_sum)) {
                min_sum = current_sum;
                ans = current_sum;
            }
        }
    }
    cout << ans << endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
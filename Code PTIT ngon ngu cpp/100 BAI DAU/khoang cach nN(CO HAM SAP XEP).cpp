
#include <iostream>
#include <vector> // dung cho vector
#include <algorithm> // dung cho sort
using namespace std;
int main() {
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		sort(a.begin(), a.end());
		long long nn=a[1]-a[0];
		for (int i = 2; i < n; i++) {
			if(a[i]-a[i-1]<nn){
				nn=a[i]-a[i-1];
			}
		}
		cout << nn << endl;
	}
    return 0;
}
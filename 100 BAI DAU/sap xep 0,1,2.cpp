
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
		for (int i = 0; i < n; i++) {
			cout<<a[i]<<" ";
		}
		cout<<endl;
	}
    return 0;
}
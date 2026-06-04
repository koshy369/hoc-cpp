
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
		int j=0;
		for (int i = n-1; i >=(n/2.0); i--) {
			cout<<a[i]<<" "<<a[j++]<<" ";
		}
		if(n%2!=0) cout<<a[j];
		cout<<endl;
	}
    return 0;
}
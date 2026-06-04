#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int k;
	cin>>k;
	vector<long long> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());

	int tong=0;
	for(int i=1; i<k ;i++){
		if(a[i]-a[i-1]>0) tong+=a[i]-a[i-1]-1;
	}
	cout<<tong<<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
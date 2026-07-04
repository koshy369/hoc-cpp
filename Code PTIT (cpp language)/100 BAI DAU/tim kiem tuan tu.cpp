#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int k,q;
	cin>>k>>q;
	vector<long long> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for(int i=1; i<k ;i++){
		if(a[i]==q){
			cout<<i+1<<endl;
			return;
		}
	}
	cout<< -1<<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
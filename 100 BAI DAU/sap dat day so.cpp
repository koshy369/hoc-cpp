#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int k;
	cin>> k;
	vector<long long> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	for(int i=0; i< k ;i++){
		int ok=1;
		for(int j=0; j< k ;j++){
			if(i==a[j]){
				cout<<a[j]<<" ";
				a[j]=-1;
				ok=0;
				break;
			}
		}
		if (ok){
			cout<<"-1 ";
		}
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}



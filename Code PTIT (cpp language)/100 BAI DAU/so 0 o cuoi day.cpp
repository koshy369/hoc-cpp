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
	int dem=0;
	for(int i=0; i< k ;i++){
		if(a[i]!=0){
			cout<<a[i]<<" ";
		}
		else dem++;
	}
	for(int i=0; i< dem ;i++){
		cout<<0<<" ";
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
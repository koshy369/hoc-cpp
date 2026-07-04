#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int k;
	cin>>k;
	k=k-1;
	vector<long long> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	long long dem=1;
	for(int i=0; i<k ;i++){
		if(a[i]!=dem){
			cout<<dem<<endl;
			return;
		}
		else dem++;
	}
	cout<< a[a.size()-1]+1<<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
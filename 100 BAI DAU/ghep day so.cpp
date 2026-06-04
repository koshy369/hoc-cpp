#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int m,e;
	cin>>m>>e;
	int k=m*e;
	long long a[k];
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a, a+k);
	for(int i=0; i<k ;i++){
		cout<<a[i]<<" ";
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
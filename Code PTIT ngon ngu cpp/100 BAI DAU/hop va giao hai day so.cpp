#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve(){
	int m,e;
	cin>>m>>e;
	int k=m+e;
	vector<long long> a(k);
	for(int i = 0; i < k; i++) {
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	long long c[e+m][2]={},dem=0;
	c[0][0]=1;
	c[0][1]=a[0];
	for(int i=1; i< k ;i++){
		if(a[i]!= a[i-1]){
			c[++dem][1]=a[i];
		}
		c[dem][0]++;
	}
	for(int i=0; i<=dem ;i++){
		cout<<c[i][1]<<" ";
	}
	cout<<endl;
	for(int i=0; i<=dem ;i++){
		if( c[i][0]>1 )cout<<c[i][1]<<" ";
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
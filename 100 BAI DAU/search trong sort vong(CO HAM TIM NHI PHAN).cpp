#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long long tknphan(long long x,long long a[],long long dau,long long cuoi){
	long long left=dau,right=cuoi;
	while (left<=right){
		long long mid = left +(right-left)/2;
		if (a[mid]==x) return mid+1;
		else if(a[mid]<x) left=mid+1;
		else right=mid-1;
	}
	return -1;
}
void solve(){
	int k,n;
	cin>>k>>n;
	long long a[k];
	cin>> a[0];
	int tick=0;
	for(int i = 1; i < k; i++) {
		cin >> a[i];
		if(a[i]< a[i-1]) tick=i;
	}
	long long dau=tknphan(n,a,0,tick);
	long long sau=tknphan(n,a,tick,k-1);
	if(dau!=-1){
		cout<<dau<<endl;
	}
	else cout<<sau <<endl;
}
int main(){
	int n;
	cin>>n;
	while (n--){
		solve();
	}
	return 0;
}
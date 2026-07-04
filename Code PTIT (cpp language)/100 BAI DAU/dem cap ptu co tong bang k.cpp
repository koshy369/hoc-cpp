#include <iostream>
using namespace std;
void solve(){
	int m,e;
	cin>>m>>e;
	long long a[m];
	for(int i = 0; i < m; i++) 
		cin >> a[i];
	long long tong=0;
	for(int i=0; i<m-1 ;i++){
		if(a[i]>e) continue;
		for(int j=i+1;j<m;j++){
			if(a[i]>e) continue;
			if(a[i]+a[j]==e){
				tong+=1;
			}
		}
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

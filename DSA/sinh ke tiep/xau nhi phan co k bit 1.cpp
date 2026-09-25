#include <bits/stdc++.h>
using namespace std;
int n,m;
vector<int>  a;
vector<vector<int>> luu;
int dem1;
int solve() {
	int i;
    for(i=n-1;i>=0;i--){
    	if (a[i]==0){
    		a[i]+=1;
            dem1 ++;
    		for(int j=i+1;j<n; j++){
    			a[j]=0;
			}
            dem1-=n-i-1;
			return 1;
		}
	}
	return 0;
}
void out(){
	for(int x: a){
		cout<<x;
	}
	cout<<"\n";
}
int main() {
    int t; cin>>t;
    while(t--){
    	luu.clear();
        dem1=0;
    	cin>>n>>m;
    	a.assign(n,0);
    	for (int i=0;i<n ;i++ ){
        	a[i]=0;
    	}
        if (m==0) out();
    	while(solve()){
    		if (dem1==m)out();
		}
    }
    
}

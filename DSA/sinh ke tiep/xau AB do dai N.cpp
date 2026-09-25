#include <bits/stdc++.h>
using namespace std;
int n,dem=0;
vector<int>  a;
vector<vector<int>> luu;
int solve() {
	int i;
    for(i=n-1;i>=0;i--){
    	if (a[i]==0){
    		a[i]+=1;
    		for(int j=i+1;j<n; j++){
    			a[j]=0;
			}
			return 1;
		}
	}
	return 0;
}
void out(){
	for(int x: a){
		if(x==0){
			cout<<"A";
		}
		else cout<<"B";
	}
	cout<<" ";
}
int main() {
    int t; cin>>t;
    while(t--){
    	luu.clear();
    	cin>>n;
    	a.assign(n,0);
    	for (int i=0;i<n ;i++ ){
        	a[i]=0;
    	}
    	out();
    	while(solve()){
    		out();
		}
		cout<< endl;
    }
    
}

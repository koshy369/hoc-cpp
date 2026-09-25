#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;
vector<char>  a;
int checkout(){
	int x=0,y=0;
	for (int i=0;i<n-2 ;i++ ){
		if(a[i]=='H' && a[i+1]=='H') return 0;
	}
	return 1;

}
int solve() {
	int i;
    for(i=n-2;i>=1;i--){
    	if (a[i]=='A'){
    		a[i]='H';
    		for(int j=i+1;j<n-1; j++){
    			a[j]='A';
			}
			return 1;
		}
	}
	return 0;
}
void out(){
	for(auto x: a){
		cout<<x;
	}
	cout<<"\n";
}
int main() {
	int t; cin>>t;
    while(t--){
		cin>>n;
		a.assign(n,0);
		for (int i=1;i<n ;i++ ){
			a[i]='A';
		}
		a[0]='H';
		if(checkout()) out();
		while(solve()){
			if(checkout()){
				out();
			}
		}
	}
    
}

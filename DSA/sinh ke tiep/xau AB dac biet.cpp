#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;
vector<char>  a;
vector<vector<char>> luu;
int checkout(){
	int x=0,y=0;
	for (int i=0;i<n ;i++ ){
		if(a[i]=='A') x++;
		else{
			if(x>m) return 0;
			if(x==m) y++;
			x=0;
		} 
	}
	if(x>m) return 0;
	if(x==m) y++;
	return y==1;

}
int solve() {
	int i;
    for(i=n-1;i>=0;i--){
    	if (a[i]=='A'){
    		a[i]='B';
    		for(int j=i+1;j<n; j++){
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
	cin>>n>>m;
	a.assign(n,0);
	for (int i=0;i<n ;i++ ){
		a[i]='A';
	}
	if(checkout()) out();
	while(solve()){
		if(checkout()){
			luu.push_back(a);
			dem++;
		}
	}
	cout<<dem<<"\n";
	for(auto x: luu){
		for(auto y: x){
			cout<<y;
		}
		cout<<"\n";
	}
    
}

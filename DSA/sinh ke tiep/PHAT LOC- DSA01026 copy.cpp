#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;
string  a;
bool checkout(const string &str) {
    if (str.find("88") != string::npos) return false;
    if (str.find("6666") != string::npos) return false;
    return true;
}
int solve() {
	int i;
    for(i=n-2;i>=1;i--){
    	if (a[i]=='6'){
    		a[i]='8';
    		for(int j=i+1;j<n-1; j++){
    			a[j]='6';
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
	cin>>n;
	a.assign(n,'0');
	for (int i=1;i<n ;i++ ){
		a[i]='6';
	}
	a[0]='8';
	if(checkout(a)) out();
	while(solve()){
		if(checkout(a)){
			out();
		}
	}
    
}

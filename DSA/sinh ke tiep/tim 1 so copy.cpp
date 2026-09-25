#include <bits/stdc++.h>
using namespace std;
int n, m,k,ok=0;
string a,b;
vector<long long> luu;
int solve() {
	if (n>18) return 0;
	if (ok==0){
		a.assign(n,'0');
		a[0]='9';
		ok=1;
        luu.push_back(stoll(a));
        return 1;
	}
    for(int i=n-1;i>0;i--){
    	if (a[i]=='0'){
    		a[i]='9';
    		for(int j=i+1;j<n; j++){
    			a[j]='0';
			}
			luu.push_back(stoll(a));
			return 1;
		}
	}
	n++;
	ok=0;
	return 1;
}
int main() {
	int n=1;
	while(solve());
    int t; cin>>t;
    while(t--){
    	cin>>m;
    	for (auto x : luu){
        	if (x%m==0){
				cout<<x<<"\n";
				break;
			}
    	}
    }
}

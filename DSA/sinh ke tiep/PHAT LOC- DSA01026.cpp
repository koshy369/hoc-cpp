#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;
vector<char>  a;
int checkout(){
	int x=0,y=0;
	int max_chuoi6=0, dem6=0;
	int max_chuoi8=0, dem8=0;
	for (int i=0;i<n ;i++ ){
		if(a[i]=='8'){
			dem8++;
			if(dem6>max_chuoi6){
				max_chuoi6 =dem6;
				if(max_chuoi6>3) return 0;
			}
			dem6=0;
		}
		if(a[i]=='6'){
			dem6++;
			if(dem8>max_chuoi8){
				max_chuoi8 =dem8;
				if(max_chuoi8>1) return 0;
			}
			dem8=0;
		}
	}
	if(dem6>max_chuoi6){
		max_chuoi6 =dem6;
		if(max_chuoi6>3) return 0;
	}
	if(dem8>max_chuoi8){
		max_chuoi8 =dem8;
		if(max_chuoi8>1) return 0;
	}
	return 1;

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
	a.assign(n,0);
	for (int i=1;i<n ;i++ ){
		a[i]='6';
	}
	a[0]='8';
	if(checkout()) out();
	while(solve()){
		if(checkout()){
			out();
		}
	}
    
}

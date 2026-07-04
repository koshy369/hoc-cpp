#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define vll vector<long long>
ll n,k,tong=0;
vll num;
void in(){
	cin>>n>>k;
}
void solve(){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			ll times=i*j;
			if(times%4 != 0) tong++;
		}
	}
}
void out(){
	cout<<tong+k<<endl;
}
int main(){
	in(); solve(); out();
	return 0;
}

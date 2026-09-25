#include <bits/stdc++.h>
using namespace std;
int n,m,dem=0;
vector<char>  a;
vector<long long>  gt;// giai thua

void tienXuLy(){
	gt.assign(12,1);
	for(int i=1; i<12; i++){
		gt[i] = gt[i-1] * i;
	}
}

int solve() {
	long long sum =1;
    for(int i=0; i<n; i++){
    	long long p = n-i-1;
		int q=0;
		for(int j=i+1; j<n; j++){
			if(a[j]< a[i]) q+=1;
		}
		sum += gt[p] *q;
	}
	return sum;
}

int main() {
	tienXuLy();
	int t; cin>>t;
    while(t--){
		cin>>n;
		a.assign(n,0);
		for (int i=0 ; i<n ; i++ ){
			cin>>a[i];
		}
		cout<<solve()<<"\n";
	}
    
}

#include <iostream>
#include <vector>
using namespace std;
#define MAXN 100001
int B[MAXN]={};
int uocnn(int n){
	if (n <= 3) return n;
    if (n % 2 == 0) return 2;
	if (n % 3 == 0) return 3;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0) return i;
		if ( n % (i + 2) == 0) return i+2;
    }
    return n;
}
void xuly(){
	for(long k=1; k <MAXN;k++){
		B[k]=uocnn(k);
	}
}
void solve(){
	long long a;
	cin >>a;
	for (long k=1;k<=a;k++){
		cout<<B[k]<<" ";
		
	}
	cout<<endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	xuly();
	int test;
	cin >>test;
	while (test--){
		solve();
	}	
    return 0;
}
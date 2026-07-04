#include <iostream>
using namespace std;
int solve(long long a,long long k){
	int dem=0;
	while (a%2==0){
		dem++;
		if (dem ==k) return 2;
		a/=2;
	}

	while (a%3==0){
		dem++;
		if (dem ==k) return 3;
		a/=3;
	}

	for (long long i=5;i*i<=a;i+=6){
		while (a%i==0){
			dem++;
			if (dem ==k) return i;
			a/=i;
		}
		while (a%(i+2)==0){
			dem++;
			if (dem ==k) return i+2;
			a/=(i+2);
		}
	}
	if (a>1){
		dem++;
		if (dem ==k) return a;
	}
	return -1;
}
int main()
{
	int test;
	cin >>test;
	while (test--){
		long long a,k;
		cin >>a>>k;
		cout<<solve(a,k)<<endl;
	}
    return 0;
}
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >>test;
	while (test--){
		long long a;
		cin >>a;
		long long lnhat=0;
		if (a%2==0){
			lnhat=2;
			while (a%2==0){
				a/=2;
			}
		}
		if (a%3==0){
			lnhat=3;
			while (a%3==0){
				a/=3;
			}
		}
		for (long k=5;k*k<=a;k+=6){
			if (a%(k)==0){
				while (a%k==0){
					lnhat=k;
					a/=k;
				}
			}
			if (a%(k+2)==0){
				while (a%(k+2)==0){
					lnhat=k+2;
					a/=(k+2);
				}
			}
		}
		if (a>lnhat){
			lnhat=a;
		}
		cout<<lnhat<<endl;
	}
	return 0;
}

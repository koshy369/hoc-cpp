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
		if (a%2==0){
			while (a%2==0){
				a/=2;
				cout<<2<<" ";
			}
		}
		if (a%3==0){
			while (a%3==0){
				a/=3;
				cout<<3<<" ";
			}
		}
		for (long k=5;k*k<=a;k+=6){
			if (a%(k)==0){
				while (a%k==0){
					cout<<k<<" ";
					a/=k;
				}
			}
			if (a%(k+2)==0){
				while (a%(k+2)==0){
					cout<<k+2<<" ";
					a/=(k+2);
				}
			}
		}
		if (a>1){
			cout<< a<<" ";
		}
		cout<<endl;
	}
	return 0;
}
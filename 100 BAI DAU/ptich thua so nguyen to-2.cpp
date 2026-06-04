#include <iostream>
using namespace std;
int main()
{
	long long a;
	cin >>a;
	if (a%2==0){
			cout<<2<<" ";
			int dem=0;
			while (a%2==0){
				dem++;
				a/=2;
			}
			cout<<dem<<endl;
	}
	if (a%3==0){
			cout<<3<<" ";
			int dem=0;
			while (a%3==0){
				dem++;
				a/=3;
			}
			cout<<dem<<endl;
	}
	for (long k=5;k*k<=a;k+=6){
		if (a%(k)==0){
			cout<< k<<" ";
			int dem=0;
			while (a%k==0){
				dem++;
				a/=k;
			}
			cout<<dem<<endl;
		}
		if (a%(k+2)==0){
			cout<< k+2<<" ";
			int dem=0;
			while (a%(k+2)==0){
				dem++;
				a/=(k+2);
			}
			cout<<dem<<endl;
		}
	}
	if (a>1){
		cout<< a<<" "<<1<<endl;
	}
	cout<<endl;
    return 0;
}

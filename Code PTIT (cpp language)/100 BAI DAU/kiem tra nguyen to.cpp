#include <iostream>
using namespace std;
int snt(long long n){
	if (n<2) return 0;
	if(n%2==0 && n!=2) return 0;
	if(n%3==0 && n!=3) return 0;
	for (long i=5;i*i<=n;i+=6){
		if (n%i==0 || n%(i+2)==0) return 0;
	}
	return 1;
}
int main()
{
	int a;
	cin >>a;
	if (snt(a)==0){
		cout<<"NO"<<endl;
		return 0;	
	}
	cout<<"YES"<<endl;		
    return 0;
}

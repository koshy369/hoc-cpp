#include <iostream>
using namespace std;
int lienke(long long k){
	long long a=0,b=k;
	while (b>0){
		int so=b%10;
		a=a*10+ so;
		b/=10;
	}
	if (k==a) return 1;
	return 0;
}
int main()
{
    int test;
    cin >>test;
    while (test--){
        long long so;
        cin >>so;
        if(lienke(so)){
            cout<< "YES"<<endl;
        }
        else cout<< "NO"<<endl;
    }
    return 0;
}

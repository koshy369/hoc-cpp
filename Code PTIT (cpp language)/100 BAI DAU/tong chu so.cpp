#include <iostream>
using namespace std;
int tongcacso(long long k){
	long long b=k,tong=0;
	while (b>0){
        tong+=b%10;
        b/=10;
	}
	return tong;
}
int main()
{
    int test;
    cin >>test;
    while (test--){
        long long so;
        cin >>so;
        while (so>=10){
            so=tongcacso(so);
        }
        cout<< so<<endl;
    }
    return 0;
}

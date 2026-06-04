#include <iostream>
using namespace std;
int notslp(long long k){
	if (k==0 || k==6 || k==8) return 0;
	return 1;
}
int main()
{
    int test;
    cin >>test;
    while (test--){
        long long a,ok=1;
        cin >>a;
        while (a>0){
            int so = a%10;
            if (notslp(so)==1){
                ok=0;
                break;
            }
            a/=10;
        }
        if(ok==1){
            cout<< "YES"<<endl;
        }
        else cout<< "NO"<<endl;
    }
    return 0;
}

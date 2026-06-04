#include <iostream>
using namespace std;
int lienke(long long k){
	long long b=k;
    int trc=b%10,sau=0;
    b/=10;
	while (b>0){
		sau=b%10;
        if(!(trc==sau+1 || trc==sau-1)){
            return 0;
        }
		trc=sau;
        b/=10;
	}
	return 1;
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

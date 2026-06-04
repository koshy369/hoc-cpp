#include <iostream>
using namespace std;
int ucnn(long long  a1, long long  b1){
	long long  a=a1,b=b1;
    while(b!=0){
        int r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    int test;
    cin >>test;
    while(test--){
        long long  n;
        cin>> n;
        long long j=1;
        for(int i=2;i<=n;i++){
            long long  u=ucnn(i,j);
            j=((i*j)/u);
        }
        cout<< j<<endl;
    }
    return 0;
}

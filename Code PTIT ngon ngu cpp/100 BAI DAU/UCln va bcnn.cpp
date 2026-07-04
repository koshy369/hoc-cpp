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
        long long  i,j;
        cin>> i>> j;
        if(j>i){
        	long long temp=i;
        	i=j;
        	j=temp;
		}
        long long  u=ucnn(i,j);
        long long  bcnn=((i*j)/u);
        cout<< bcnn<<" "<< u<<endl;
    }
    return 0;
}

#include <iostream>
using namespace std;
int chan_le(long long k){
	long long chan=0,le=0,b=k;
	while (b>0){
		int so=b%10;
		if (so%2==0) chan++;
        else le++;
		b/=10;
	}
    if(le==chan)return 1;
	return 0; 
}
int main()
{
    long long mu[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int a, b;
    cin >>a;
    int dem=0;
    for(long  i=mu[a-1]+1; i<mu[a]; i++){
        if(chan_le(i)) {
            long k=i;
            if((i-1)%10==0){
                while(i<k+9){
                    dem++;
                    cout<<i<<" ";
                    if (dem==10){
                        dem=0;
                        cout<<endl;
                    }
                    i+=2;
                }
            }
        }
        else {
            dem++;
            cout<<i<<" ";
            if (dem==10){
                dem=0;
                cout<<endl;
            }
        } 
    }
    if (dem!=0) cout<<endl;
    return 0;
}
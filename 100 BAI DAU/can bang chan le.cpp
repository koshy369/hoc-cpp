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
	return (le==chan); 
}
int main()
{
    long long mu[10] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};
    int a;
    cin >> a;
    int dem = 0;
    long long start = mu[a-1]; 
    long long end = mu[a];
    for(long long i = start; i < end; i++){
        if(chan_le(i)) {
            cout << i << " ";
            dem++;
            if (dem == 10){
                dem = 0;
                cout << endl;
            }
        }  
    }
    if (dem != 0) cout << endl;
    return 0;
}

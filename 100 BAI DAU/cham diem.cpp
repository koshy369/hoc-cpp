#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char D[2][15] = {
    {'A', 'B', 'B', 'A', 'D', 'C', 'C', 'A', 'B', 'D', 'C', 'C', 'A', 'B', 'D'},
    {'A', 'C', 'C', 'A', 'B', 'C', 'D', 'D', 'B', 'B', 'C', 'D', 'D', 'B', 'B'}
};
    int test;
    cin >>test;
    while (test--){
    	char bl[15];
        double diem=0.0;
        int de;
        cin>>de;
		long long k=0;
		if (de==102) k=1;
		for (int i=0;i<15;i++){
			cin>>bl[i];
			if (bl[i]==D[k][i]){
				diem+=1.0/1.5;
			}
		}
        cout << fixed << setprecision(2) << diem;
    }
    return 0;
}

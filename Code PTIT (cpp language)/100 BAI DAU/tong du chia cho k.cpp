#include <iostream>
using namespace std;
int main()
{
	int test;
	cin >>test;
	while (test--){
		long long a,b;
		cin >>a>>b;
		long long tong =0;
		for (long long i=0;i<=a;i++){
			tong +=i%b;
		}
		if (tong==b){
			cout << "1" << endl;
		} else {
			cout << "0" << endl;
		}
	}
    return 0;
}
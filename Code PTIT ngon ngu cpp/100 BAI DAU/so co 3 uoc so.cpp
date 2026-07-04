#include <iostream>
using namespace std;
#define MAXN 10000
bool A[MAXN]={};
void snto(){
	A[0]=true;
	A[1]=true;
	for(long i=2;i*i<=MAXN;i++){
		if (A[i]==false){
			for (long j=i*i;j<=MAXN;j+=i){
				A[j]=true;
			}
		}
	} 
}
void solve(long long a){
	snto();
	for (long long i=2;i*i<=a;i++){
		if (!A[i]){
			cout << i*i << " ";
		}
	}
	cout << endl;
}
int main()
{
	int test;
	cin >>test;
	while (test--){
		long long a;
		cin >>a;
		solve(a);
	}
    return 0;
}
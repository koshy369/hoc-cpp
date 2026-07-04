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
int main()
{
	int test;
	cin >>test;
	while (test--){
		int a;
		cin >>a;
		snto();
		for (long k=2;k<=a;k++){
			if (a%k==0 && A[k]==false){
				cout<< k<<" ";
				int dem=0;
				while (a%k==0){
					dem++;
					a/=k;
				}
				cout<<dem<<" ";
			}
		}
		cout<<endl;
	}
		
    return 0;
}

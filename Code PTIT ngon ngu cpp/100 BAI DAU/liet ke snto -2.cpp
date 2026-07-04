#include <iostream>
using namespace std;
#define MAXN 10000
bool A[MAXN]={};
void snto(){
	A[0]=true;
	A[1]=true;
	for(long i=2;i<=MAXN;i++){
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
		int a,b;
		cin >>a>>b;
		snto();
		for (long k=a;k<=b;k++){
			if (A[k]==false) cout<< k<<" ";
		}
		cout<<endl;
	}
    return 0;
}

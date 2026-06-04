#include <iostream>
using namespace std;
#define MAXN 1000000
bool nsnt[MAXN]={};
void snto(){
	nsnt[0]=true;
	nsnt[1]=true;
	for(long i=2;i*i<=MAXN;i++){
		if (nsnt[i]==false){
			for (long j=i*i;j<=MAXN;j+=i){
				nsnt[j]=true;
			}
		}
	} 
}
void solve(){
	int a;
	cin >>a;
	snto();
	for (long k=2;k<=a/2;k++){
		if (nsnt[k]==false && nsnt[a-k]==false){
			cout<< k<< " " << a-k << " "<<endl;
			return;
		}
	}
	cout<< -1<<endl;

}
int main()
{
	int test;
	cin >>test;
	while (test--){
		solve();
	}
    return 0;
}

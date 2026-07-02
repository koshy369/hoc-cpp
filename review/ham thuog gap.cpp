#include <bits/stdc++.h>
using namespace std;
const long long max_val = 1e8 +7;
bool nsnt[max_val]={};
void snto(){
	nsnt[0]=true;
	nsnt[1]=true;
	for(long i=2;i*i<=max_val;i++){
		if (nsnt[i]==false){
			for (long j=i*i;j*j<=max_val;j+=i){
				nsnt[j]=true;
			}
		}
	} 
}

bool isPrime(long long a){
    if (a<=1) return 0;
    if (a%2==0 || a%3==0) return 0;
    for (int i=5; i*i<=a;i+=6){
        if(a%i==0 || a%(i+2)==0) return 0;
    }
    return 1;
}
int ucnn(int a,int b){// a<b
	if(a>b) swap(a,b);
	int r=b;
	while (a>0){
		r=b%a;
		a=b;
		b=r;
	}
	return a;
}
int bcnn(int a,int b){
	return a*b/ucnn(a,b);
}
bool isPrimee(long long a){
    cout<<"2 \n3\n";
    for (int i=5; i*i<=a;i+=6){
        cout<<i<<endl<<(i+2)<<endl;
    }
    return 1;
}
int main(){
	isPrimee(1000);
}

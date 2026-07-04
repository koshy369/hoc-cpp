#include <iostream>
#include <vector>

using namespace std;
#define MAXN 1000001
bool B[MAXN]={};
int gandoixung(int n) {
    string s;
    while (n>0){
        s+=(char)(n%10);
        n/=10;
    }
    float len=s.length()-1;
    int j=len,dem=0;
    for(int i=0; i<len/2 ; i++){
        if(s[i]!=s[j]) dem++;
        j--;
    }
    return(dem<=1);
}
void xuly(){
	for(long k=1; k <MAXN;k++){
		B[k]=gandoixung(k);
	}
}
void solve(){
	long long a,b;
	cin >>a>>b;
    int dem=0;
	for (long k=a;k<=b;k++){
		if(B[k]) dem++;
	}
	cout<<dem<<endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	xuly();
	int test;
	cin >>test;
	while (test--){
		solve();
	}	
    return 0;
}
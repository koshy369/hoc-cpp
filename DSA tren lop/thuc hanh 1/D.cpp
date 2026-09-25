#include<bits/stdc++.h>
using namespace std;
string a;
int n,m;
int sinh() {
	int i;
    for(i=n-1;i>=0;i--){
    	if (a[i]=='0'){
    		a[i]='1';
    		for(int j=i+1;j<n; j++){
    			a[j]='0';
			}
			return 1;
		}
	}
	return 0;
}
void xuat(){
   for(auto i:a){
      cout<<i<<" ";
   }
   cout<<endl;
}
int main(){
   cin>>n>>m;
   int dem=0;
   a.assign(n,'0');
   cout<<a<<"\n";
   while(sinh()){
        dem++;
        if (dem%m==0){
            cout<<a<<"\n";
        }
   }
}
#include<bits/stdc++.h>
using namespace std;
int n,m;
int ucnn(int a, int b){
   if (b>a) swap(a,b);
   int r=a;
   while(b>0){
      r=a%b;
      a=b;
      b=r;
   }
   return a;
}
int main(){
   cin>>n>>m;
   int u= ucnn(n,m);
   cout<<n/u<<" "<<m/u;
}
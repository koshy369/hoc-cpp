#include<bits/stdc++.h>
using namespace std;
vector<int> a;
int n;
int sinh(){
   int i= n-1;
   while (i>=0 && a[i]==1){
      a[i--]=0;
   }
   if (i>=0){
      a[i]=1;
   }
   else return 0;
   return 1;
}
void xuat(){
   for(auto i:a){
      cout<<i<<" ";
   }
   cout<<endl;
}
int main(){
   cin>>n;
   a.assign(n,0);
   xuat();
   while(sinh()){
      int ok=1;
      for(int i=0;i<=(n-1)/2; i++){
         if (a[i]!=a[n-1-i]){
            ok=0;
            break;
         }
      }
      if(ok) xuat();
   }
   cout;
}
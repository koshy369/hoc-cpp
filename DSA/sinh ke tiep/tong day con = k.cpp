#include<bits/stdc++.h>
using namespace std;
vector<int> a,b;
int n,m;
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
   for(int i=0; i<n;i++){
      if(a[i]) cout<<b[i]<<" ";
   }
   cout<<endl;
}
int main(){
   int dem=0;
   cin>>n>>m;
   a.assign(n,0);
   b.resize(n);
   xuat();
   for(auto &x: b){
      cin>>x;
   }
   while(sinh()){
      int sum=0;
      for(int i=0;i<n; i++){
         if(a[i]==1) sum+=b[i];
      }
      if(sum==m){
         xuat();
         dem++;
      }
   }
   cout<<dem;
}
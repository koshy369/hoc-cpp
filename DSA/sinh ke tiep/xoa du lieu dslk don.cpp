#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++){
      cin>>a[i];
   }
   cin>>m;
   for(int i=0;i<n;i++){
      if(a[i]==m){
         a.erase(a.begin()+i);
         i--;
         n--;
      }
      
   }
   for(int x: a){
      cout<<x<<" ";
   }
   cout<<endl;
}
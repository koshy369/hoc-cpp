#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e,h;
int main(){
   cin>>a>>b>>c;
   e=(a-1)/2;
   d=(a-c)/2;
   h=(a+1)/2;
   n=1;
   while(h--){
      for(int i=0;i<e;i++) cout<<" ";
      for(int i=0;i<n;i++) cout<<"*";
      for(int i=0;i<e;i++) cout<<" ";
      e--;
      n+=2;
      cout<<endl;
   }
   while(b--){
      for(int i=0;i<d;i++) cout<<" ";
      for(int i=0;i<c;i++) cout<<"*";
      for(int i=0;i<d;i++) cout<<" ";
      cout<<endl;
   }
}
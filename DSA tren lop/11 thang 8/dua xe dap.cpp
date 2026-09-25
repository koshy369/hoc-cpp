#include<bits/stdc++.h>
using namespace std;
int n,m,a,b,c,d,e,h;
typedef struct ng{
   float s, v;
}ng;
int main(){
   cin>>n;
   float min=1e9+7;
   int stt;
   vector<ng> x(n);
   for(int i=0;i<n; i++){
      cin>>x[i].s>> x[i].v;
      if (min > x[i].s/x[i].v){
         min = x[i].s/x[i].v;
         stt = i+1;
      }
   }
   cout<<stt;
}
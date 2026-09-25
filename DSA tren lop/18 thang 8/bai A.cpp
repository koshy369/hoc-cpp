#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
   cin>>n;
   vector<int> a(n);
   for(int i=0;i<n;i++){
      cin>>m;
      if(i>0) a[i]=a[i-1]+m;
      else a[i]=m;
   }
   cin>>m;
   while(m--){
      int x; cin>>x;
      int r= lower_bound(a.begin(),a.end(),x)-a.begin()+1;
      cout<<r<<endl;
   }
}
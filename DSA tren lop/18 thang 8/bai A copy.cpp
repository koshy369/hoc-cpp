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
   vector<int> b(m);
   for(int i=0;i<m;i++){
      cin>>b[i];
   }
   for(int i=0;i<m;i++){
      int mid=0,
         high=n-1,
         low=0;
      while ( low <=high) { 
         int mid = (low + high)/2; 
		   if ( b[i] > a[mid] ) low = mid; 
		   else if( b[i] < a[mid] ) high = mid; 
         else cout<<mid<<endl;
      }
   }
}
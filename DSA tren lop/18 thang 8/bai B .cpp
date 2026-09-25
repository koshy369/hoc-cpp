#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int main(){
   int test; cin>>test;
   while (test--){
      cin>>n>>x;
      vector<int> a(n);
      for(int i=0;i<n;i++){
         cin>>a[i];
      }
      int mid,
         high=2*1e9,
         low=0;
      while ( low <=high) { 
         int mid = (low + high)/2; 
         if ( x > a[mid] ) low = mid+1; 
         else if ( x < a[mid] ) high = mid -1; 
         else cout<<mid; 
      }
   }
}
#include<bits/stdc++.h>
using namespace std;
vector<int> a,ticked, save;
int dem =0;
int n,m;
void xuat(){
   for(auto x: save){
      cout<<x<<" ";
   }
   cout<<endl;
}
void Try(int k){
   if (k==n){
      dem++;
      xuat();
      return;
   }
   for(int i=0; i<n;i++){
      if(!ticked[i]){
         ticked[i]=1;
         save.push_back(a[i]);
         Try(k+1);
         ticked[i]=0;
         save.pop_back();
      }
   }
}
int main(){
   cin>>n;
   a.assign(n,0);
   ticked.assign(n,0);
   for(int i=0;i<n; i++){
      cin>>a[i];
   }
   sort(a.begin(), a.end());
   Try(0);
}
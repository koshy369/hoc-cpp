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
int check(){
   vector<int> s;
   s=save;
   sort(s.begin(), s.end());
   if (s==save) return 1;
   return 0; 
}
void Try(int k,int j){
   if (k==m){
      if (check()) dem++;
      return;
   }
   for(int i=j; i<n;i++){
      if(!ticked[i]){
         ticked[i]=1;
         save.push_back(a[i]);
         Try(k+1,i+1);
         ticked[i]=0;
         save.pop_back();
      }
   }
}
int main(){
   cin>>n>>m;
   a.assign(n,0);
   ticked.assign(n,0);
   for(auto &x: a){
      cin>>x;
   }
   Try(0,0);
   cout<<dem;
}
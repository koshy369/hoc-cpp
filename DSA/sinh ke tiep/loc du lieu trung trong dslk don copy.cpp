#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
   cin>>n;
   int dem=0;
   unordered_map<int,int> a;
   vector<int> b;
   for(int i=0;i<n;i++){
      cin>>m;
      if (a.find(m)==a.end()){
         a[m]=dem++;
         b.push_back(m);
      }
   }
   for (int i=0; i<dem; i++) { 
        cout << b[i] << " ";
   }
   cout<<endl;
}
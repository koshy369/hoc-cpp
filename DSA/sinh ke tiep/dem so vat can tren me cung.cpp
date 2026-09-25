#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<vector<int>> a;
vector<vector<int>> b;
void tinh(int c,int d){
   if(c>=n||c<0|| d<0|| d>=m) return;

   if(a[c][d] == 0 || b[c][d] == 1) return;
   b[c][d]=1;
   
   b[c][d]=1;
   tinh(c+1,d);
   tinh(c,d+1);
   tinh(c-1,d);
   tinh(c,d-1);
}
int main(){
   cin>>n>>m;
   int sum=0;
   a.assign(n, std::vector<int>(m, 0));
   b.assign(n, std::vector<int>(m, 0));
   for(int i=0;i<n;i++){
      string s;
      getline(cin>>ws , s);
      int j=0;
      for(char c: s){
         if(c=='#') a[i][j]=1;
         j++;
      }      
   }
   for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
         if(a[i][j] == 1 && b[i][j] == 0){
            tinh(i,j);
            sum++;
         }
      }
   }
   cout<<sum<<endl;
}
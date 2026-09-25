#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a,canh(100);
vector<int> save;// canh
int dem =0;
int n,m,c,d,e,f,x,y;
void solve1(){
    save.assign(n,0);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            (i==j)? save[i]+=a[i][j]*2 : save[i]+=a[i][j];
        }
   }
   for(int i=0;i<n;i++){
        cout<<save[i]<< (i == n - 1 ? "" : " ");
   }
   cout<<endl;

}
void solve2(){
    canh.assign(n,vector<int> ());
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if (a[i][j]>0) {
                canh[i].push_back(j+1);
            }
        }
   }
   cout<<n<<endl;
   for(int i=0;i<n;i++){
        cout<<canh[i].size()<<" ";
        for(int x: canh[i]){
            cout<<x<<" ";
        }
        cout<<endl;
   }
   

}
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
   cin>>x>>n;
   a.assign(n,vector<int>(n,0));
   (x==1) ? solve1() : solve2() ;
   return 0;

}
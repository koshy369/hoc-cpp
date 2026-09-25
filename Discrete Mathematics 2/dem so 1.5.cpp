#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a,canh;
vector<int> save;
int dem;
int n,m,c,d,e,f,x,y;
void solve1(){
    save.assign(n,0);
    for(int i=0;i<m;i++){
        cin>>c>>d;
        save[c-1]++;
        save[d-1]++;
   }
   for(int i=0;i<n;i++){
        cout<<save[i]<< (i == n - 1 ? "" : " ");
   }
   cout<<endl;

}
void solve2(){
    canh.assign(n,vector<int> ());
    dem = 0;
    for(int i=0;i<m;i++){
        cin>>c>>d;
        canh[c-1].push_back(d-1);
        canh[d-1].push_back(c-1);
   }
   cout<<n<<endl;
   for(int i=0;i<n;i++){
        cout<<canh[i].size()<<" ";
        for(int x: canh[i]){
            cout<<x+1<<" ";
        }
        cout<<endl;
   }

}
int main(){
    
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
   cin>>x;
   cin>>n>>m;
   canh.clear();
   (x==1) ? solve1() : solve2() ;
   return 0;

}
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a,canh(100);
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
    a.assign(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        cin>>e;
        while (e--){
            cin>>c;
            canh[i].push_back(c-1);
        }
   }
   for(int i=0;i<n;i++){
        for(int x: canh[i]){
            a[i][x]=1;
        }
   }
   cout<<n<<endl;
   for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
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
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> save;
vector<pair<int, int>> canh;// canh
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
    a.assign(n+1, vector<int> (n+1,0));
    dem = 0;
    for(int i=0;i<m;i++){
        cin>>c>>d;
        a[c][d]=1;
        a[d][c]=1;
   }
   cout<<n<<endl;
   for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
   }
   cout<<endl;

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
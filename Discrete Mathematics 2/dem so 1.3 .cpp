#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> save;
vector<pair<int, int>> canh;// canh
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
    canh.clear();
    dem = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
            if (j>=i && a[i][j]>0) {
                canh.push_back({i+1, j+1});
                dem++;
            }
        }
   }
   cout<<n<<" "<<dem<<endl;
   for(int i=0;i<n;i++){
        for(int j=0;j<dem;j++){
            if(i==canh[j].first || i==canh[j].second){
                cout<<1<<(j==dem ? "" : " ");
            }
            else cout<<0<<(j==dem ? "" : " ");
        }
        cout<<endl;
   }
   cout<<endl;
}
int main(){
    freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
   cin>>x>>n;
   a.assign(n,vector<int>(n,0));
   (x==1) ? solve1() : solve2() ;
   return 0;

}
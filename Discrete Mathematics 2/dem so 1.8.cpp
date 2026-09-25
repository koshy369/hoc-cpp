#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> save;
int dem;
vector<pair<int, int>> canh;
int n,m,c,d,e,f,x,y;
void solve1(){
    cin>>m;
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
    for(int i=0;i<n;i++){
        cin>>c;
        for(int j=0; j <c; j++){
            cin>>d;
            a[i][d-1]=1;
        }
    }
    canh.clear();
    dem = 0;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            if (a[i][j] > 0){
                canh.push_back({i+1, j+1});
                dem++;
            }
        }
    }
    cout << n << " " << dem << endl;
    for(int i = 0 ; i< dem ; i++){
        cout<<canh[i].first<<" "<<canh[i].second<<endl;
    }
    cout<<endl;

}
int main(){
     freopen("DT.INP", "r", stdin);
    freopen("DT.OUT", "w", stdout);
   cin>>x;
   cin>>n;
   canh.clear();
   (x==1) ? solve1() : solve2() ;
   return 0;

}
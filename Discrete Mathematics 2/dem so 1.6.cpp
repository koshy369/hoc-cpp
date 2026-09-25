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
    canh.clear();
    dem = 0;
    for(int i=0;i<m;i++){
        cin>>c>>d;
        canh.push_back({c-1,d-1});
        dem++;
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
#include<bits/stdc++.h>
using namespace std;
int n,m,ok=0;
vector<char> s;
vector<vector<int>> a;
vector<vector<int>> b;
void thembot(int c,int d,int ok){
        if(ok){
            if (c==1)s.push_back('D');
            else s.push_back('R');
        }
        else{
            s.pop_back();
        }

}
void tinh(int c,int d){
    if ((c==n-1 && d==n-1)){
        ok=1;
        for(auto x: s ){
            cout<< x;
        }   
        cout<<" ";
        return;
    }

    if(c < n && c>=0 && d>=0 && d<n){
        if( a[c][d] == 1 && b[c][d] == 0) {

            b[c][d]=1;
            if (c + 1 < n && a[c + 1][d] == 1) {
                thembot(1,0,1);
                tinh(c+1,d);
                thembot(1,0,0);
            }
            if (d + 1 < n && a[c ][d+1] == 1) {
                thembot(0,1,1);
                tinh(c,d+1);
                thembot(0,1,0);
            }
            b[c][d]=0;
       }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ok=0;
        s.clear();
        a.assign(n, std::vector<int>(n, 0));
        b.assign(n, std::vector<int>(n, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<n; j++){
                cin>> a[i][j];
            }     
        }

        if (a[0][0] == 1) {
            tinh(0, 0);
        }
        if (!ok) cout<<"-1";
        cout<<"\n";
    }
}
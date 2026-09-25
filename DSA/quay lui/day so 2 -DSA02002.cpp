#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<vector<int>> a1;
int dem=0;

void out(){
    reverse(a1.begin(), a1.end());
    for (auto x: a1){
        int m=(int)x.size();
        cout << "[" ;
        for(int i=0; i<m; i++){
            cout<< x[i] << ( (i==m-1 ) ? "] " : " ");
        }
    }
    cout<<"\n";
}
void solve(int k) {
    int m = (int)a1[k].size();
    if (m==1) return;
    vector<int> a(m-1,0);
    for (int i = 0; i <m-1; i++) {
        a[i]= a1[k][i]+ a1[k][i+1];
    }
    a1.push_back(a);

    solve(k+1);
}

void in(){
    dem=0;
    cin>>n;
    a1.clear();
    vector<int> a(n,0);
    for (int i=0; i<n; i++){
        cin>>a[i];
    }
    a1.push_back(a);
}


int main() {
    int t; cin>>t;
    while(t--){
        in();
        solve(0);
        out();
    }
     return 0;
}
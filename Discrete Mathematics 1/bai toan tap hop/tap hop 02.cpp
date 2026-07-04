#include <bits/stdc++.h>

using namespace std;

set<int> giaohaith(set<int> a, set<int> b){
    set<int> A_giao_B;
    for (int s: a){
        if(b.find(s)!=b.end()){
            A_giao_B.insert(s);
        }
    }
    return A_giao_B;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    set<int> a;
    set<int> b;
    int n,nhap; cin>>n;
    for(int i=1;i<=n ; i++){
        cin>>nhap;
        if(nhap) a.insert(i);
    }
    for(int i=1;i<=n ; i++){
        cin>>nhap;
        if(nhap) b.insert(i);
    }
    set<int> c= giaohaith(a,b);
    cout<<c.size()<<endl;
    for(int i : c){
        cout<<i<<" ";
    }

    return 0;
}
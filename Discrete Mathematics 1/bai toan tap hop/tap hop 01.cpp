#include <bits/stdc++.h>

using namespace std;

set<int> hop_hai_th(set<int> a, set<int> b){
    for (int i: a){
        b.insert(i);
    }
    return b;
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
    set<int> c= hop_hai_th(a,b);
    cout<<c.size()<<endl;
    for(int i : c){
        cout<<i<<" ";
    }

    return 0;
}
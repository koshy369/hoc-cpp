#include <bits/stdc++.h>
using namespace std;

/*cau hinh dau: 0000
cau hinh cuoi: 1111
=> thay
*/

bool sinh(vector<int>& a,int n){
    for(int i=n-1; i>=0;i--){
        if (a[i]){ //a[i]=1;
            a[i]=0;
            return 1;
        }
        a[i]=1;
    }
    return 0;
}

void solve(){
    int n,k; cin>>n>>k;
    vector<int> a(n);
    for (int &x : a){
        cin>>x;
    }
    while (k--){
        if(sinh(a,n)){
            for (int x : a){
                cout<<x<<" ";
            }
        }
        else cout<<"0";
        cout<<endl;
    }
}
int main(){
    solve();
}


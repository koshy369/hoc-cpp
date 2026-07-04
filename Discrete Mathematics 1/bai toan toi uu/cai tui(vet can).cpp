#include <bits/stdc++.h>
using namespace std;
void Sinh(vector<long long> &s,int n, bool &isLast) {
    // Tìm vị trí 0 đầu tiên từ bên phải sang
    int i = n - 1;
    while (i >= 0 && s[i] == 1) {
        s[i] = 0;
        i--;
    }
    // Nếu tìm thấy 0, chuyển thành 1
    if (i >= 0) {
        s[i] = 1;
    } else {
        isLast = true; // Đã đến cấu hình cuối cùng "11...1"
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //cout<<"So loai do vat: ";
    long long n; cin>>n;
    //cout<<"Trong luong tui: ";
    long long P; cin>>P;
    vector<long long> vp(n); // vector trong luong
    vector<long long> value(n);
    for(int i=0;i<n;i++){
        cin>>vp[i];
        cin>>value[i];
    }

    long long max_val=0;
    bool isLast = false;
    vector<long long>  results(n);
    vector<long long> s(n, 0);

    while(!isLast){
        
        long long p=0,m=0;
        for(int i=0;i<n;i++){
            if(s[i]) {
                p+=vp[i];
                m+=value[i];
            }
        }
        if(p<=P && m>max_val){
            max_val=m;
            results=s;
        }
        Sinh(s,n,isLast);
    }
    cout<<max_val<<endl;
    for(int i=0;i<n;i++){
        cout<<results[i]<<" ";
    }
    return 0;
}
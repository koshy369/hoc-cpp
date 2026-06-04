#include <bits/stdc++.h>
using namespace std;
void Sinh(vector<int> &s,int n, bool &isLast) {
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
    cout<<"So loai do vat: "; int n; cin>>n;
    cout<<"Trong luong tui: "; int P; cin>>P;

    cout<<"Vector trong luong: ";
    vector<float> vp(n); // vector trong luong
    for(int i=0;i<n;i++){
        cin>>vp[i];
    }

    cout<<"Vector gia tri su dung: ";
    vector<float> value(n); //gtri
    for(int i=0;i<n;i++){
        cin>>value[i];
    }

    double money=0;
    bool isLast = false;
    vector<int>  save(n);
    vector<int> s(n, 0);

    while(!isLast){
        
        int p=0,m=0;
        for(int i=0;i<n;i++){
            if(s[i]) {
                p+=vp[i];
                m+=value[i];
            }
        }
        if(p<=P && m>money){
            money=m;
            save=s;
        }
        Sinh(s,n,isLast);
    }
    cout<<fixed<<setprecision(1)<<"chi phi toi uu: "<<money<<endl;
    cout<<"Phuong an toi uu: ";
    for(int i=0;i<n;i++){
        cout<<save[i]<<" ";
    }
    return 0;
}
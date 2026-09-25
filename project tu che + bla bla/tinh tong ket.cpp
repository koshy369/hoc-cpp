#include <bits/stdc++.h>
using namespace std;

void solve(){
    vector<float> so;
    int count=1;
    while(true){        
        cout<<"Hoc phan "<< count <<": "<<endl;
        string dauvao;
        float tongket=0,f,dem=0;
        so.clear();
        
        cout<<"Nhap: ";
        getline(cin>>ws, dauvao);
        
        stringstream ss(dauvao);
        while (ss>>f){
            dem++;
            so.push_back(f);
        }
        for(int j=0; j<dem; j+=2){
            tongket+=so[j]*so[j+1]/100;
            //so[i] la diem, so[i+1]la phan tram
        }
        cout<<fixed<<setprecision(2)
            <<"Mon "<<count++<<": "
            <<tongket <<"       "
            << tongket*4/10<<endl;
    }
}

int main(){
    cout<<"\n\n------------CHUONG TRINH TINH DIEM TONG KET-------------\n";
    cout<<"*Nhap cac diem va % tuong ung cho moi lan tinh\n\n";
    while (true) solve();
}

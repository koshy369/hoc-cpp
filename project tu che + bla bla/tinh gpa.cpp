#include <bits/stdc++.h>
using namespace std;
struct HocPhan{
    float tk, tin;
    HocPhan(float a, float b): tk(a),tin(b) {}
};
vector<HocPhan> hp;

string DiemChu(float n){
    if(n <=3.94) return "F";
    if(n <=4.94) return "D";
    if(n<=5.44) return "D+";
    if(n <=6.44) return "C";
    if(n <=6.94) return "C+";
    if(n <=7.94) return "B";
    if(n <=8.44) return "B+";
    if(n <=8.94) return "A";
    else return "A+";
}
void solve(){
    cout<<"\n\n--------------CHUONG TRINH TINH DIEM GPA-----------------\n\n";
    cout<<"Tinh diem tphan hay ko(1/0): ";
    int select; cin>>select;
    cout<<"Nhap so mon: ";
    int n; cin>>n;
    vector<float> so;
    if (select!=0){
        for(int i=0; i<n; i++){
        	cout<<"Hoc phan "<< i+1 <<": "<<endl;
        	float Tinchi=0,f,tongket=0;
            int dem=0;
            string dauvao;
            
            do {
                cout << "Nhap cac diem va % tuong ung: ";
                getline(cin >> ws, dauvao);

                dem = 0;
                so.clear();
                
                stringstream ss(dauvao);
                while (ss >> f) {
                    dem++;
                    so.push_back(f);
                }
                if (dem % 2 != 0) {
                    cout << "Loi: Ban nhap bi le roi! Kiem tra lai xem co sot % cua diem nao khong.\n";
                }
            } while (dem % 2 != 0);

            cout<<"Nhap so tin chi: ";
            cin>>Tinchi;

            for(int j=0; j<dem; j+=2){
                tongket+=so[j]*so[j+1]/100;
                //so[j] la diem, so[j+1]la phan tram
            }
            hp.push_back(HocPhan(tongket,Tinchi));
        }
    }
    else {
        cout<<"Thu tu nhap: Diem -> Tin chi\n";
        for(int i=0; i<n; i++){
            float Tinchi=0; 
            float tongket=0;
            cout<<"Mon "<<i+1<<": "; cin>>tongket>>Tinchi;
            hp.push_back(HocPhan(tongket,Tinchi));
        }
    }
    cout<<"----------------------KET QUA----------------------"<<endl<<endl;
    float gpa10=0, gpa4=0,tongtinchi=0;
    for(int i=0; i<n; i++){
        gpa10+=hp[i].tk*hp[i].tin;
        tongtinchi+=hp[i].tin;
        if(select==1)cout<<fixed<<setprecision(2)
                        <<"Mon "<<i+1<<": "<<hp[i].tk <<"_______" << hp[i].tk*4/10<<
                        "_______" << DiemChu(hp[i].tk)<<endl;
    }
    
     gpa10/=tongtinchi;
     gpa4=gpa10*4/10;
     cout<<fixed<<setprecision(2)<<endl
            <<"thang diem 4: "<<gpa4<<endl<<
            "thang diem 10: "<<gpa10<<endl<<
            "diem chu: "<<DiemChu(gpa10); 
    cout<<endl<<endl;
}

int main(){
    while (true){
        hp.clear();
        solve();
    }  
}

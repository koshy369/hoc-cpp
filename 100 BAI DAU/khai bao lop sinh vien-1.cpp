#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct SinhVien{
    string msv="B20DCCN001";
    string ten="";
    string lop="";
    string dob="";
    double gpa;
    void nhap (){
        getline(cin,ten);
        getline(cin,lop);
        getline(cin,dob);
        cin>>gpa;
    }
    void xuat(){
        cout<<msv<<" "<<ten<<" "<<lop<<" ";
        for (size_t i=0 ; i<dob.length() ; i++){
            if(dob[i]=='/') dob[i]=' ';
        }
        stringstream ss(dob);
        string token;
        while(ss>>token){
            if (token.length()==1) cout<<"0"<<token<<"/";
            else if (token.length()==2) cout<<token<<"/";
            else cout<<token<<" ";
        }
        cout<<fixed<<setprecision(2)<<gpa;
    }
};

int main(){
    struct SinhVien a;
    a.nhap();
    a.xuat();
    return 0;
}
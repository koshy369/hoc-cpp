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

};
void nhap (SinhVien &a){
    getline(cin,a.ten);
    getline(cin,a.lop);
    getline(cin,a.dob);
    cin>>a.gpa;
    
}
void in(SinhVien &n){
    cout<<n.msv<<" "<<n.ten<<" "<<n.lop<<" ";
    for (size_t i=0 ; i<n.dob.length() ; i++){
        if(n.dob[i]=='/') n.dob[i]=' ';
    }
    stringstream ss(n.dob);
    string token;
    while(ss>>token){
        if (token.length()==1) cout<<"0"<<token<<"/";
        else if (token.length()==2) cout<<token<<"/";
        else cout<<token<<" ";
    }
    cout<<fixed<<setprecision(2)<<n.gpa;
}
int main(){
    struct SinhVien a;
    nhap(a);
    in(a);
    return 0;
}
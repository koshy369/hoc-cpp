#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct SinhVien{
    string msv="N20DCCN001";
    string ten="";
    string lop="";
    string dob="";
    double gpa;

};
void nhapThongTinSV (SinhVien &a){
    string s;
    getline(cin,a.ten);
    cin>>a.lop>>a.dob>>a.gpa;
    if (a.dob[1] == '/') a.dob = "0" + a.dob;
    if (a.dob[4] == '/') a.dob.insert(3, "0");
}
void inThongTinSV(SinhVien &a){
    cout<<a.msv<<" "
        <<a.ten<<" "
        <<a.lop<<" "
        <<a.dob<<" "
        << fixed << setprecision(2) << a.gpa;
}
int main(){
    struct SinhVien a;
    nhapThongTinSV(a);
    inThongTinSV(a);
    return 0;
}
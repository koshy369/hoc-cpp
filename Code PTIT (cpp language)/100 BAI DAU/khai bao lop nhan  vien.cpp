#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std;

class NhanVien {
private:
    string msv,ten,sex,dob,address,msthue,ngaykihopdong;
public:
    NhanVien(){
        this->msv="00001";
        this->sex="";
        this->dob="";
        this->address="";
        this->msthue="";
        this->ngaykihopdong="";
    }

    friend istream& operator  >> (istream& in, NhanVien &nv) {
        getline(in >> ws, nv.ten);
        in >> nv.sex 
            >> nv.dob;
        getline(in >> ws, nv.address);
        in >>nv.msthue
            >>nv.ngaykihopdong;
        return in;
    }
    friend ostream& operator << (ostream& out, NhanVien &nv) {
        out <<nv.msv<<" "<< nv.ten << " " 
             << nv.sex << " " 
             << nv.dob << " " 
             << nv.address << " " 
             << nv.msthue << " " 
             << nv.ngaykihopdong;
        return out;
    }
};

int main(){
    NhanVien a;
    cin >> a;
    cout << a;
    return 0;
}
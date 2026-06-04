#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class SinhVien {
private:
    string msv, ten, lop, dob;
    float gpa;

public:
    SinhVien() {
        this->msv = "B20DCCN001";
        this->ten = "";
        this->lop = "";
        this->dob = "";
        this->gpa = 0;
    }
    friend istream& operator >> (istream& in, SinhVien &sv) {
        getline(in >> ws, sv.ten);
        in >> sv.lop >> sv.dob >> sv.gpa;
        if (sv.dob[1] == '/') sv.dob = "0" + sv.dob;
        if (sv.dob[4] == '/') sv.dob.insert(3, "0");
        
        
        stringstream ss(sv.ten);
        string token, res = "";
        while (ss >> token) {
            transform(token.begin(), token.end(), token.begin(), ::tolower);// chuyen ve chu thuong het
            token[0] = toupper(token[0]);
            res += token + " ";
        }
        res.erase(res.length() - 1);
        sv.ten = res;
        
        return in;
    }

    friend ostream& operator << (ostream& out, SinhVien sv) {
        out << sv.msv << " " << sv.ten << " " << sv.lop << " " 
            << sv.dob << " " << fixed << setprecision(2) << sv.gpa;
        return out;
    }
};

int main() {
    SinhVien a;
    cin >> a;
    cout << a;
    return 0;
}
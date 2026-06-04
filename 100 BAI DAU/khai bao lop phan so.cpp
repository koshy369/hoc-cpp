#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

class PhanSo {
public:
    long long tu, mau;

    PhanSo(long long t, long long m) {
        tu = t;
        mau = m;
    }
    friend istream& operator  >> (istream& in, PhanSo &ps) {
        in >> ps.tu >> ps.mau;
        return in;
    }
    void rutgon(){
        long long a=abs(tu),b=abs(mau);
        if (b>a) swap (a,b);
        while(b>0){
            long long r=a%b;
            a=b;
            b=r;
        }
        tu=tu/a;
        mau/=a;
    }

    friend ostream& operator << (ostream& out, PhanSo &ps) {
        out << ps.tu << "/" << ps.mau ;
        return out;
    }
};

int main() {
	PhanSo p(1,1);
	cin >> p;
	p.rutgon();
	cout << p;
	return 0;
}
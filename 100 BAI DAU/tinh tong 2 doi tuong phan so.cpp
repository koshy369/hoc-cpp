#include <iostream>
#include <sstream>
#include <algorithm>
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
    void rutgon() {
        long long common = __gcd(abs(tu), abs(mau));
        tu /= common;
        mau /= common;
        if (mau < 0) {
            tu = -tu;
            mau = -mau;
        }
    }
    PhanSo operator + (const PhanSo& b) {
        long long tm=this->tu*b.mau+b.tu*this->mau;
        long long mm=this->mau * b.mau ;
        PhanSo ketqua(tm,mm);
        ketqua.rutgon();
        return ketqua;
    }
    friend ostream& operator << (ostream& out, PhanSo ps) {
        out << ps.tu << "/" << ps.mau ;
        return out;
    }
};

int main() {
	PhanSo p(1,1), q(1,1);
	cin >> p >> q;
	cout << p + q;
	return 0;
}
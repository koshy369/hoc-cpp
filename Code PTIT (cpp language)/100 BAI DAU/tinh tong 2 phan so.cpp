#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct SinhVien{
    long long tu,mau;

};
long long ucln(long long a,long long b){
    if (b>a) swap (a,b);
    while(b>0){
        long long r=a%b;
        a=b;
        b=r;
    }
    return a;
}
SinhVien tong(SinhVien a,SinhVien b){
    SinhVien result;
    result.tu=a.tu*b.mau +b.tu*a.mau;
    result.mau= a.mau*b.mau;
    return result;
}
void nhap (SinhVien &a){
    cin>> a.tu>>a.mau;
}
void in(SinhVien &n){
    long long uc=ucln(n.tu,n.mau);
    cout<<n.tu/uc<<"/"<<n.mau/uc;
}
int main() {
	struct SinhVien p,q;
	nhap(p); nhap(q);
	SinhVien t = tong(p,q);
	in(t);
	return 0;
}
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
void nhap (SinhVien &a){
    cin>> a.tu>>a.mau;
}
void in(SinhVien &n){
    long long uc=ucln(n.tu,n.mau);
    cout<<n.tu/uc<<"/"<<n.mau/uc;
}
int main(){
    struct SinhVien A;
    nhap(A);
    in(A);
    return 0;
}
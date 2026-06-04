#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct ThiSinh{
    string ten="";
    string ngaysinh="";
    double sum;

};
void nhap (ThiSinh &a){
    getline(cin,a.ten);
    getline(cin,a.ngaysinh);
    double x,y,z;
    cin>> x>>y>>z;
    a.sum= x+y+z;
}
void in(ThiSinh n){
    cout<<n.ten<<" "<<n.ngaysinh<<" ";
    cout<<fixed<<setprecision(1)<<n.sum;
}
int main(){
    struct ThiSinh A;
    nhap(A);
    in(A);
    return 0;
}
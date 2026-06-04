#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct SinhVien{
     double x, y;

};
void input (SinhVien &a){
    cin>>a.x>>a.y;
}
double distance(SinhVien n,SinhVien m){
    return hypot(n.x-m.x,n.y-m.y);
}
int main(){
    struct SinhVien A, B;
    int t;
    cin>>t;
    while(t--){
        input(A); input(B);
        cout << fixed << setprecision(4) << distance(A,B) << endl;
    }
    return 0;
}
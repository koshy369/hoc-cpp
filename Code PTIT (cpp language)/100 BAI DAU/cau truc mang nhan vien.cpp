#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct SinhVien{
    string msv="0000";
    string ten="";
    string sex="";
    string dob="";
    string address="";
    string msthue="";
    string ngaykihopdong="";

};
void nhap (SinhVien &a){
    getline(cin>> ws,a.ten);
    getline(cin,a.sex);
    getline(cin,a.dob);//date of bith
    getline(cin,a.address);
    getline(cin,a.msthue);
    getline(cin,a.ngaykihopdong);
    
}
void inds(SinhVien ds[], int N) {
    for (int i = 0; i < N; i++) {
        cout << setfill('0') << setw(5) << i + 1 << " ";
        cout << ds[i].ten << " " 
             << ds[i].sex << " " 
             << ds[i].dob << " " 
             << ds[i].address << " " 
             << ds[i].msthue << " " 
             << ds[i].ngaykihopdong << endl;
    }
}
int main(){
    struct SinhVien ds[50];
    int N,i;
    cin >> N;
    for(i = 0; i < N; i++) nhap(ds[i]);
    inds(ds,N);
    return 0;
}
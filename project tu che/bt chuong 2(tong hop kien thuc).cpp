#include <iostream>
#include <vector>
#include <memory>
using namespace std;
int cong(int a,int b) {return a+b ;}
int nhan(int a,int b) {return a*b ;}

void tinh(int x,int y,int (*pheptoan)(int,int)){
    cout<<"ket qua: " <<(*pheptoan)(x,y)<<endl;
}
void In1(int so){
    if(so>0 && so %2==0) cout<< "so "<<so<<" dung la so chan duong\n";
    else cout<< "so "<<so<<" kphai la so chan duong\n";
}
void solve() {
    // ----- KHAI BAO DONG-------
    int* n=new int;// neu gan gia tri luon thi(vd 5)  new int(5) 
    cin>>*n;
    int *a= new int[*n]; // mảng động tên a có n phần tử
    for (int i=0; i<*n;i++){
        cin>>*(a+i); // cung co the dung a[i] nhu 1 mang thuong
    }
    // con tro ham(tu dong xoa khi het ham):
    void (*ptrIn)(int)=&In1;// khong & cung duoc
    int (*ConG)(int,int)=cong;// =>khong & cung duoc

    //
     ptrIn(1); // cach goi ngan gon
     (*ptrIn)(1); //cach goi tuong minh

    ConG(1,1);

    for (int i=0; i<*n; i++){
        ptrIn(*(a+i));
        cout<<"binh phuong cua a["<<i<<"]: ";
        tinh( a[i], *(a+i), nhan);
        cout<<"2*a["<<i<<"]: ";
        tinh( a[i], a[i], cong);
        cout<<endl;
    }
    // --------GIAI PHONG BO NHO:-------
    //mang dong khong xoa thi KHONG MAT
    delete[] a;
    delete n;
    return;
}

int main() {
    solve();
    return 0;
}
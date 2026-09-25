#include <iostream>
#include <vector>
#include <string>
/*
Số lượng bit 1 là chẵn: lật bit cuối cùng(phải nhất) của chuỗi .
Số lượng bit 1 là lẻ: tìm bit 1 đầu tiên tính từ bên phải sang,lật bit ngay bên trái nó.
Trường hợp đặc biệt (Mã cuối cùng): vdu: 1000000
*/
using namespace std;
string a;
int n;
int nextGrayCode() {
    int first=-1, count=0;
    for(int i=0; i<n;i++){
        if (a[i]=='1'){
            count++;
            first =i;
        }
    }
    if (count==1 && first==0) return 0;
    if (count%2==0 ){
        a[n-1]= (a[n-1]=='0') ? '1': '0';
    }
    else {
        a[first-1] = (a[first-1]=='0') ? '1': '0';
    }
    return 1;
}
void out(){
    cout<<a<<" ";
}

int main() {
    int t;cin>>t;
    while (t--){
        cin >> n;
        a="";
        for(int i=0; i<n;i++){
            a+='0';
        }
        out();
        while(nextGrayCode()){
            out();
        }
        cout<<"\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <string>
using namespace std;
string a,b;
int n;
int XOR(int x,int y){
    return ((x&&!y) || (y&&!x)) +'0';
}
void ToBinaryCode() {
    int first=-1, count=0;
    for(int i=1; i<n;i++){
         a[i]=XOR(a[i]-'0',a[i-1]-'0');
    }
}
void out(){
    cout<<a<<"\n";
}

int main() {
    int t ; cin>>t;
    while (t--){
        getline(cin>>ws, a);
        n=a.length();
        ToBinaryCode();
        out();
    }
    return 0;
}
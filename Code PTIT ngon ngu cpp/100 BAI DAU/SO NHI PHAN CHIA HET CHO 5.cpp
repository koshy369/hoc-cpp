#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    
    int n; cin >> n;
    cin.ignore();
    while (n--){
        string s="";
        cin >> s;
        int len=s.length();
        int r=0;
        for (int i=0;i<len;i++){
            int k =s[i]-'0';
            r=(2*r+k)%5;
        }
        if (r==0){
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }
    }
    return 0;
}
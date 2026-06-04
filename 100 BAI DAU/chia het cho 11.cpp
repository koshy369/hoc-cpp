#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;
void solve() {
    string input="";
    getline(cin,input);
    long chan=0;
    long le=0;
    for (size_t i=0;i< input.length();i++){
        if(i%2==0){
            chan += (input[i]-'0');
        }
        else le += (input[i]-'0');
    }
    if((chan-le)%11==0){
        cout<<"1"<<endl;
    }
    else cout<<"0"<<endl;
}
int main() {
    int t;
    cin>> t;
    cin.ignore();
    while (t--) solve();
    return 0;
}
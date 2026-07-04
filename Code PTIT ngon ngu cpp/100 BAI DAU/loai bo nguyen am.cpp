#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;

void chuthuong(string &s){
    for (size_t i=0;i<s.length();i++){
        s[i]=tolower(s[i]);
    }
}
void solve() {
    string S="";
    getline(cin,S);
    int len= S.length();
    for(int i=0;i<len;i++){
        char c=S[i];
        c=tolower(c);
        if (c!='a'&&c!='e'&&c!='i'&&c!='e'&&c!='o'&&c!='u'&&c!='y'){
            cout<<"."<<c;
        }
    }
}
int main() {
    solve();
    return 0;
}
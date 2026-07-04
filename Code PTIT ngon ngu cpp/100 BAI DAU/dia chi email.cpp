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
    string input="";
    getline(cin,input);
    vector<string> words;
    string begin="";
    stringstream ss(input);
    string token;
    while (ss>>token){
        chuthuong(token);
        words.push_back(token);
    }
    cout << words.back();
    for (size_t i=0;i< words.size()-1;i++){
        cout<< words[i][0];
    }
    cout<<"@ptit.edu.vn"<<endl;
}
int main() {
    solve();
    return 0;
}
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
string chuhoa(string &s){
    for (size_t i=0;i<s.length();i++){
        s[i]=toupper(s[i]);
    }
    return s;
}
void solve() {
    string input="";
    getline(cin,input);
    vector<string> words;
    stringstream ss(input);
    string token;
    while (ss>>token){
        chuthuong(token);
        token[0]=toupper(token[0]);
        words.push_back(token);
    }
    size_t len =words.size()-1;
    for (size_t i=0;i< len ;i++){
        cout<< words[i];
        if(i<len-1){
            cout<<" ";
        }
    }
    cout <<", "<<chuhoa(words.back());
}
int main() {
    solve();
    return 0;
}
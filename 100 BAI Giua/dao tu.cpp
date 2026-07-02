#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>

using namespace std;
void solve() {
    string input="";
    getline(cin>>ws,input);
    vector<string> words;
    stringstream ss(input);
    string token;
    while (ss>>token){
        words.push_back(token);
    }
    int  len =words.size()-1;
    for (int i=len ;i>=0; i--){
        cout<< words[i];
        if(i>0){
            cout<<" ";
        }
    }
    cout<<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    if (!(cin >> test)) return 0;
    while (test--) {
        solve();
    }
    return 0;
}
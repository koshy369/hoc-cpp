#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void solve() {
    string input;
    if (!getline(cin, input)) return;
    int chan=0,le=0,soso=0;
    stringstream ss(input);
    string token;
    while (ss>>token){
        int i=token[token.length()-1]-'0';
        if (i%2==0){
            chan++;
        }
        else le++;
        soso++;
    }
    if(soso%2==0 && chan>le) cout<<"YES";
    else if ((soso%2!=0 && chan<le)) cout<<"YES";
    else cout<<"NO";
    cout<<endl;

}

int main() {
    int test;
    if (!(cin >> test)) return 0;
    cin.ignore();
    while (test--) {
        solve();
    }
    return 0;
}
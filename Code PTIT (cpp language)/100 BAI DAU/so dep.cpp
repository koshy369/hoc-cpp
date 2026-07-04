#include <iostream>
#include <string>
#include <set>

using namespace std;
void solve(string s){
    int len=s.length();
    string s1="";
    for (int i=len-1;i>=0;i--){
        if((s[i]-'0')%2==0){
            s1=s1+s[i];
        }
        else {
            cout<<"NO"<<endl;
            return;
        }
    }
    if (s==s1){
        cout<<"YES"<<endl;
        return;
    }
    else {
        cout<<"NO"<<endl;
        return;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); 

    while(n--) {
        string s;
        string s1;
        getline(cin, s);
        solve(s);
    }

    return 0;
}
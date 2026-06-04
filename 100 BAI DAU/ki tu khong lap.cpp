#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int len = s.length();
    int dem = 0;
    int a[len][2];
    for (int i = 0; i < len; i++) {
        int ok=0;
        for (int j = 0; j < dem; j++) {
            if((int)s[i] == a[j][0]) {
                a[j][1]++;
                ok=1;
                break;
            }
        }
        if (ok==0){
            a[dem][0]=s[i];
            a[dem][1]=1;
            dem++;
        }
    }
    for (int i = 0; i < dem; i++) {
        if(a[i][1]==1){
            cout << (char)a[i][0];
        }
    }
    cout<< endl;
}
int main() {
    int test;
    cin >> test;
    cin.ignore();
    while (test--) solve();
    return 0;
}
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void solve() {
    string s;
    getline(cin, s);
    int k; cin>>k;
    cin.ignore();
    int len = s.length();
    if (len < 26) {
        cout << "0" << endl;
        return;
    }
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
    int temp=0;
    for (int i = 0; i < dem; i++) {
        if(a[i][1]>0){
            temp++;
        }
    }
    if(temp+k>=26){
        cout << "1" << endl;
    } else {
        cout << "0" << endl;
    }
}
int main() {
    int test;
    cin >> test;
    cin.ignore();
    while (test--) solve();
    return 0;
}
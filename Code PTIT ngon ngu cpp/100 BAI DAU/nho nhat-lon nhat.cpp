#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;
    if (s == 0) {
        if (m == 1) cout << "0 0" << endl;
        else cout << "-1 -1" << endl;
        return 0;
    }
    if (s > 9 * m) {
        cout << "-1 -1" << endl;
        return 0;
    }
    string lonNhat = "";
    int tempS = s;
    for (int i = 0; i < m; i++) {
        int digit = min(9, tempS);
        lonNhat += (digit + '0');
        tempS -= digit;
    }
    string beNhat = "";
    tempS = s;
    for (int i = 0; i < m; i++) {
        if (i < m - 1) {
            int digit = min(tempS - 1, 9); 
            beNhat += (digit + '0');
            tempS -= digit;
        } else {
            beNhat += (tempS + '0');
        }
    }
    reverse(beNhat.begin(), beNhat.end());// DAO NGUOC CHUOI
    cout << beNhat << " " << lonNhat << endl;

    return 0;
}
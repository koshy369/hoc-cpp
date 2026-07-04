#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve() {
    string S;
    if (!getline(cin, S)) return;
    // Khởi tạo 26 hàng, mỗi hàng 1 phần tử, tất cả bằng 0
    vector<vector<int>> counts(27, vector<int>(2, 0));
    counts[0][0]=1;
    counts[0][1]=S[0];

    int dem=0;

    for (size_t i=1;i<S.length();i++) { 
        if(S[i]!=S[i-1]){
            counts[++dem][1]=(int)S[i];
        }
        counts[dem][0]++;
    }
    for (int i=0;i<=dem;i++) { 
        cout<<(char)counts[i][1]<<counts[i][0];
    }
    cout <<endl;
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
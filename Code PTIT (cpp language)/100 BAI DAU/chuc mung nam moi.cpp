#include <iostream>
#include <string>
#include <set>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    string line;
    getline(cin, line); 

    set<string> loichuc_docnhat;
    for (int i = 0; i < n; i++) {
        string s;
        if (getline(cin, s)) {// doc tung dong
            loichuc_docnhat.insert(s);// neu chua co thi them vao
        }
    }
    cout << loichuc_docnhat.size() << endl;

    return 0;
}
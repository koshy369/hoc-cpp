#include <bits/stdc++.h>

using namespace std;

string toLower(string s) {
    for (int i=0; i<s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    ifstream f1("DATA1.in");
    ifstream f2("DATA2.in");
    
    set<string> s1, s2, hop, giao;
    string word;
    
    while (f1 >> word) {
        s1.insert(toLower(word));
    }
    
    while (f2 >> word) {
        s2.insert(toLower(word));
    }
    
    for (string x: s1) hop.insert(x);
    for (string x: s2) {
        hop.insert(x);
        if (s1.count(x)) {
            giao.insert(x);
        }
    }
    
    bool first= true;
    for (string x: hop) {
        if (!first) cout << " ";
        cout << x;
        first = false;
    }
    cout <<endl;
    first = true;
    for (string x: giao) {
        if(!first) cout<< " ";
        cout<< x;
        first= false;
    }
    cout<< endl;
    f1.close();
    f2.close();
    return 0;
}
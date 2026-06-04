#include <bits/stdc++.h>

using namespace std;

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = tolower(s[i]);
    }
    return s;
}

int main() {
    ifstream file("VANBAN.in");
    set<string> words;
    string s;
    while (file >> s) {
        words.insert(toLower(s));
    }
    for (string x : words) {
        cout << x << endl;
    }
    file.close();
    return 0;
}
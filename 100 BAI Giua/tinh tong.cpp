#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isInt(string s) {
    if (s.empty()) return false;
    if (s.length() > 10) return false;
    long long val = 0;
    for (int i = 0; i < s.length(); i++) {
        if (!isdigit(s[i])) return false;
        val = val * 10 + (s[i] - '0');
    }
    if (val > 2147483647) return false;
    return true;
}

int main() {
    ifstream file("DATA.in");
    string s;
    long long total = 0;
    while (file >> s) {
        if (isInt(s)) {
            total += stoi(s);
        }
    }
    cout << total << endl;
    file.close();
    return 0;
}
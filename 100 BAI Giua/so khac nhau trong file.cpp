#include <iostream>
#include <fstream>
#include <map>

using namespace std;

int main() {
    ifstream file("DATA.in");
    map<int, int> mp;
    int n;
    while (file >> n) {
        mp[n]++;
    }
    for (auto x : mp) {
        cout << x.first << " " << x.second << endl;
    }
    file.close();
    return 0;
}
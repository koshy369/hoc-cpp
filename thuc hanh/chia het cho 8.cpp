#include <iostream>
#include <string>

using namespace std;

void solve() {
    string s;
    cin >> s;
    
    int n = s.length();
    long long count = 0;
    
    for (int i = 0; i < n; i++) {
        int rem8 = 0;
        int rem3 = 0;
        for (int j = i; j < n; j++) {
            int digit = s[j] - '0';
            rem8 = (rem8 * 10 + digit) % 8;
            rem3 = (rem3 * 10 + digit) % 3;
            
            if (rem8 == 0 && rem3 != 0) {
                count++;
            }
        }
    }
    
    cout << count << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
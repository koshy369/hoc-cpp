#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
bool isNotPrime[MAXN + 1];
void sieve() {
    isNotPrime[0] = isNotPrime[1] = true;
    for (int i = 2; i * i <= MAXN; i++) {
        if (!isNotPrime[i]) {
            for (int j = i * i; j <= MAXN; j += i) {
                isNotPrime[j] = true;
            }
        }
    }
}
int main() {
    int test;
    cin >> test;
    while(test--) {
        int a;
        cin >> a;
        sieve();
        for (int i = 2; i <= a; i++) {
            if (!isNotPrime[i]) cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);

    sieve();

    for (int i = max(a, 2); i <= b; i++) {
        if (!isNotPrime[i]) cout << i << " ";
    }
    return 0;
}
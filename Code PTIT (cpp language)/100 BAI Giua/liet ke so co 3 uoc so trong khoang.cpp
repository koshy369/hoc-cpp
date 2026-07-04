#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;
bool prime[MAX + 1];

void sieve() {
    for (int i = 0; i <= MAX; i++) prime[i] = true;
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= MAX; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= MAX; i += p)
                prime[i] = false;
        }
    }
}

int main() {
    sieve();
    int t;
    cin >> t;
    while (t--) {
        long long l, r;
        cin >> l >> r;
        int count = 0;
        int start = ceil(sqrt(l));
        int end = floor(sqrt(r));
        for (int i = start; i <= end; i++) {
            if (prime[i]) {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
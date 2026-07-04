#include <iostream>
#include <cmath>

using namespace std;

int sumOfDigits(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int sumOfPrimeFactorsDigits(int n) {
    int sum = 0;
    int temp = n;
    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            int digitSumOfPrime = sumOfDigits(i);
            while (temp % i == 0) {
                sum += digitSumOfPrime;
                temp /= i;
            }
        }
    }
    if (temp > 1) {
        sum += sumOfDigits(temp);
    }
    return sum;
}

void solve() {
    int n;
    cin >> n;
    if (isPrime(n)) {
        cout << "NO\n";
        return;
    }
    if (sumOfDigits(n) == sumOfPrimeFactorsDigits(n)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
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
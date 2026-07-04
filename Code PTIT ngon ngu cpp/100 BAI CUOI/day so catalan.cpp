#include <bits/stdc++.h>
using namespace std;

const long long BASE = 1000000000LL;

void multiply(vector<long long>& a, long long x) {
    long long carry = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        long long cur = a[i] * x + carry;
        a[i] = cur % BASE;
        carry = cur / BASE;
    }

    while (carry > 0) {
        a.push_back(carry % BASE);
        carry /= BASE;
    }
}

void divide(vector<long long>& a, long long x) {
    long long rem = 0;

    for (int i = (int)a.size() - 1; i >= 0; i--) {
        long long cur = rem * BASE + a[i];
        a[i] = cur / x;
        rem = cur % x;
    }

    while (a.size() > 1 && a.back() == 0) {
        a.pop_back();
    }
}

void printBigInt(const vector<long long>& a) {
    cout << a.back();

    for (int i = (int)a.size() - 2; i >= 0; i--) {
        cout << setw(9) << setfill('0') << a[i];
    }

    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;cin >> n;

    int target = n + 1;

    vector<long long> res;
    res.push_back(1);

    for (int i = 1; i <= target; i++) {
        multiply(res, 4LL * i - 2);
        divide(res, i + 1);
    }
    printBigInt(res);

    return 0;
}
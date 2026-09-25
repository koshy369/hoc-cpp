#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<long long> a;

int dem_nhom(long long x) {
    int groups = 1;
    long long cur = 0;
    for (long long v : a) {
        if (cur + v > x) {
            groups++;
            cur = v;
        } else {
            cur += v;
        }
    }
    return groups;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    a.resize(n);
    long long lo = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        lo = max(lo, a[i]);
        sum += a[i];
    }

    long long hi = sum;
    while (lo < hi) {
        long long mid = lo + (hi - lo) / 2;
        if (dem_nhom(mid) <= k) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    cout << lo << "\n";
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct HDong {
    int s;
    int f;
};

bool cmp(HDong& a, HDong& b) {
    if (a.f == b.f) {
        return a.s > b.s;
    }
    return a.f < b.f;
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
    cin >> n;
    vector<HDong> d(n);

    for (int i = 0; i < n; i++) {
        cin >> d[i].s;
    }
    for (int i = 0; i < n; i++) {
        cin >> d[i].f;
    }
    
    sort(d.begin(), d.end(), cmp);
    
    int count = 0;
    int last = -1;
    
    for (int i = 0; i < n; i++) {
        if (d[i].s >= last) {
            count++;
            last = d[i].f;
        }
    }
    
    cout << count << "\n";
    }
    
    return 0;
}
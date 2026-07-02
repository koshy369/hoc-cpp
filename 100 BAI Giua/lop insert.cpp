#include <bits/stdc++.h>

using namespace std;

class IntSet {
private:
    set<int> s;

public:
    IntSet() {}
    
    IntSet(vector<int> a) {
        for (int x : a) s.insert(x);
    }

    IntSet intersection(IntSet other) {
        IntSet res;
        for (int x : s) {
            if (other.s.count(x)) {
                res.s.insert(x);
            }
        }
        return res;
    }

    void print() {
        bool first = true;
        for (int x : s) {
            if (!first) cout << " ";
            cout << x;
            first = false;
        }
        cout << endl;
    }
};

int main() {
    ifstream fp("DATA.in");
    int n, m;
    if (!(fp >> n >> m)) return 0;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) fp >> a[i];
    for (int i = 0; i < m; i++) fp >> b[i];

    IntSet s1(a);
    IntSet s2(b);
    IntSet s3 = s1.intersection(s2);
    
    s3.print();

    fp.close();
    return 0;
}
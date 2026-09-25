#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a;

void Try(int i) {
    int can_duoi = a[i-1]+1;
    int can_tren =  n-(k-i);
    for (int j = can_duoi ; j <= can_tren ; j++) {
        a[i] = j;
        if (i == k){
            for (int o = 1; o <= k; o++) {
                cout << a[o]<<" ";
            }
            cout << "\n";
        }
        else Try(i + 1);
    }
}

int main() {
    cin >> n >> k;
    a.assign(k+1,0);
    Try(1);

    return 0;
}
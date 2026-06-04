#include <iostream>
#include <vector>

using namespace std;

void solve() {
    int n;
    cin >> n;
    int m = 4 * n;
    
    vector<vector<int>> a(m, vector<int>(m));
    int val = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = val++;
        }
    }

    int total_elements = 8 * n * n;

    // Cuộn 1
    int r1 = m / 2, c1 = m / 2 - 1;
    int dr1[] = {-1, 0, 1, 0};
    int dc1[] = {0, 1, 0, -1};
    int dir1 = 0;
    int steps1 = 2;
    int count1 = 0;

    vector<int> coil1;
    coil1.push_back(a[r1][c1]);
    count1++;

    while (count1 < total_elements) {
        for (int i = 0; i < 2 && count1 < total_elements; i++) {
            for (int j = 0; j < steps1 && count1 < total_elements; j++) {
                r1 += dr1[dir1];
                c1 += dc1[dir1];
                coil1.push_back(a[r1][c1]);
                count1++;
            }
            dir1 = (dir1 + 1) % 4;
        }
        steps1 += 2;
    }

    // Cuộn 2
    int r2 = m / 2 - 1, c2 = m / 2;
    int dr2[] = {1, 0, -1, 0};
    int dc2[] = {0, -1, 0, 1};
    int dir2 = 0;
    int steps2 = 2;
    int count2 = 0;

    vector<int> coil2;
    coil2.push_back(a[r2][c2]);
    count2++;

    while (count2 < total_elements) {
        for (int i = 0; i < 2 && count2 < total_elements; i++) {
            for (int j = 0; j < steps2 && count2 < total_elements; j++) {
                r2 += dr2[dir2];
                c2 += dc2[dir2];
                coil2.push_back(a[r2][c2]);
                count2++;
            }
            dir2 = (dir2 + 1) % 4;
        }
        steps2 += 2;
    }

    for (int i = 0; i < coil1.size(); i++) {
        cout << coil1[i] << (i == coil1.size() - 1 ? "" : " ");
    }
    cout << "\n";

    for (int i = 0; i < coil2.size(); i++) {
        cout << coil2[i] << (i == coil2.size() - 1 ? "" : " ");
    }
    cout << "\n";
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
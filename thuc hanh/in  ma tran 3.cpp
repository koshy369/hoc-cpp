#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M;
        cin >> N >> M;
        int A[105][105];
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];

        vector<int> result;
        // Tổng d = i + j chạy từ 0 đến N+M-2
        for (int d = 0; d < N + M - 1; d++) {
            if (d % 2 == 0) {
                // Đi lên: i giảm, j tăng
                int j = max(0, d - (N - 1));
                int i = min(d, N - 1);
                while (j < M && i >= 0) {
                    result.push_back(A[i][j]);
                    i--; j++;
                }
            } else {
                // Đi xuống: j giảm, i tăng
                int i = max(0, d - (M - 1));
                int j = min(d, M - 1);
                while (i < N && j >= 0) {
                    result.push_back(A[i][j]);
                    i++; j--;
                }
            }
        }

        for (int k = 0; k < result.size(); k++) {
            if (k) cout << " ";
            cout << result[k];
        }
        cout << "\n";
    }
    return 0;
}
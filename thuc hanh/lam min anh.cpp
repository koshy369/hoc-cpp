#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, M, L;
        cin >> N >> M >> L;
        
        int k = L / 2; // L = 2k+1
        
        vector<vector<int>> A(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                cin >> A[i][j];
        
        // Build 2D prefix sum (1-indexed)
        vector<vector<long long>> P(N+1, vector<long long>(M+1, 0));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                P[i][j] = A[i-1][j-1] 
                         + P[i-1][j] + P[i][j-1] - P[i-1][j-1];
        
        // Query sum của vùng [r1,c1] -> [r2,c2] (1-indexed)
        auto query = [&](int r1, int c1, int r2, int c2) -> long long {
            r1 = max(r1, 1); c1 = max(c1, 1);
            r2 = min(r2, N); c2 = min(c2, M);
            if (r1 > r2 || c1 > c2) return 0;
            return P[r2][c2] - P[r1-1][c2] 
                             - P[r2][c1-1] + P[r1-1][c1-1];
        };
        
        // Output
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                // Cửa sổ thực tế (clamp vào biên)
                int r1 = i+1-k, c1 = j+1-k;
                int r2 = i+1+k, c2 = j+1+k;
                
                // Số phần tử thực tế trong cửa sổ
                int rr1 = max(r1,1), cc1 = max(c1,1);
                int rr2 = min(r2,N), cc2 = min(c2,M);
                long long cnt = (long long)(rr2-rr1+1) * (cc2-cc1+1);
                
                long long sum = query(r1, c1, r2, c2);
                
                // Chia cho L*L (không phải số phần tử thực!)
                long long L2 = (long long)L * L;
                long long val = sum / L2;
                
                cout << val;
                if (j < M-1) cout << " ";
            }
            cout << "\n";
        }
    }
    return 0;
}
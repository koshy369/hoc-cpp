#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> A1(n), A2(m);
        map<int, int> cnt; // đếm tần suất trong A1
        
        for (int i = 0; i < n; i++) {
            cin >> A1[i];
            cnt[A1[i]]++;
        }
        for (int i = 0; i < m; i++) cin >> A2[i];
        
        set<int> inA2(A2.begin(), A2.end());
        
        vector<int> result;
        
        // Bước 1: theo thứ tự A2
        for (int x : A2) {
            if (cnt.count(x)) {
                for (int k = 0; k < cnt[x]; k++)
                    result.push_back(x);
                cnt.erase(x); // đánh dấu đã xử lý
            }
        }
        
        // Bước 2: phần tử không có trong A2, sort tăng dần
        vector<int> rest;
        for (auto& [val, freq] : cnt) {
            // cnt chỉ còn những phần tử không có trong A2
            for (int k = 0; k < freq; k++)
                rest.push_back(val);
        }
        sort(rest.begin(), rest.end());
        
        for (int x : rest) result.push_back(x);
        
        // Output
        for (int i = 0; i < result.size(); i++) {
            if (i) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
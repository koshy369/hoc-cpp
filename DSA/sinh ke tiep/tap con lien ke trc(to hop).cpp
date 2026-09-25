#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool next_to_hop(vector<int>& a, int n, int k) {

    for (int i = k - 1; i >= 0; --i) {

        int min_val = (i > 0) ? a[i-1] + 1 : 1; 
        
        if (a[i] > min_val) {
            a[i]--;
            int current_fill = n;
            for (int j = k-1; j >i; --j) { 
                a[j] = current_fill --;            }
            return true;
        }
    }
    return false;
}

int main() {
    int t; cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int> a (k);
        for (int i=0; i<k; i++){
            cin>>a[i];
        }
        if (next_to_hop(a, n, k)) {
            for (int x : a) cout << x << " ";
        } else {
            for(int i=n-k + 1;i<=n; i++){
                cout<<i<<" ";
            }
        }
        cout << "\n";
    }
    return 0;
}
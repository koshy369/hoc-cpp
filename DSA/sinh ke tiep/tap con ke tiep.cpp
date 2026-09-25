#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool next_to_hop(vector<int>& a, int n, int k) {
    for (int i = k - 1; i >= 0; --i) {
        
        if(a[i]!= n-k+i+1){//chua max
            a[i]++;
            int c = a[i];
            for (int j = i + 1; j < k; ++j) { 
                a[j] = ++ c;            }
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
            for (int i=1; i<=k; i++) cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}
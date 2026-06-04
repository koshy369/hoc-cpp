#include <iostream>
#include <vector>

using namespace std;

int N, k;
bool ok = false;
vector<bool> fixed_val;
vector<int> X;
vector<bool> used;

void printResult() {
    ok = true;
    for (int i = 1; i <= N; ++i) {
        cout << X[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

void Try(int i) {
    if (fixed_val[i]) {
        if (i == N) printResult();
        else Try(i + 1);
        return; 
    }
    for (int j = 1; j <= N; ++j) {
        if (!used[j]) { 
            X[i] = j;      
            used[j] = true; 

            if (i == N) printResult(); 
            else Try(i + 1);

            used[j] = false; 
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> k)) return 0;
    bool Conflict = false;

    fixed_val.assign(N + 1, false);
    X.assign(N + 1, 0);
    used.assign(N + 1, false);
    
    for (int i = 0; i < k; i++) {
        int u, v;
        cin >> u >> v;
    
        if (Conflict) continue;
        
        if (fixed_val[u] && X[u] != v) {
            Conflict = true;
        }
        else if (used[v] && !fixed_val[u]) {
            Conflict = true; 
        }
        else if (!fixed_val[u]) {
            X[u] = v;
            used[v] = true;
            fixed_val[u] = true;
        }
    }

    if (Conflict){
        cout << "0\n";
        return 0;
    }
    
    Try(1);
    if (!ok) cout << "0\n";
    
    return 0;
}
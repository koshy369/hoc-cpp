#include <iostream>
#include <vector>

using namespace std;
typedef struct Data{
    int u,v;
}Data;
int N, k;
bool ok = false;
vector<bool> fixed_val;
vector<int> X;
vector<Data> dataa;

void printResult() {
    ok = true;
    for (int i = 1; i <= N; ++i) {
        cout << X[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

void Try(int m) {
    if(m > N){
        int oke=1;
        for (int i = 0; i < k; i++)
            if(X[dataa[i].u]!=  dataa[i].v) oke=0;
        if(oke) printResult();
        return;
    }
    for (int j = 0; j <2 ; ++j) {
        X[m] = j;
        Try(m + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (!(cin >> N >> k)) return 0;
    bool Conflict = false;

    fixed_val.assign(N + 1, false);
    X.assign(N + 1, 0);
    dataa.resize(N + 1);
    
    for (int i = 0; i < k; i++) {
        cin >> dataa[i].u >> dataa[i].v;
    
        if (Conflict) continue;
        // xau nhi phan => v trung duoc
        if (fixed_val[dataa[i].u] && dataa[i].v != X[dataa[i].u]) {
            Conflict = true;
        }
        else if (!fixed_val[dataa[i].u]) {
            fixed_val[dataa[i].u] = true;
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
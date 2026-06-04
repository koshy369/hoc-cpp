#include <iostream>
#include <vector>

using namespace std;

int N,k;
int ok=0;
vector<int> fixed_val;
vector<int> X;
vector<int> used;
void printResult() {
    ok=1;
    for (int i = 1; i <= N; ++i) {
        cout << X[i] << (i == N ? "" : " ");
    }
    cout << "\n";
}

// Hàm quay lui để thử giá trị cho vị trí i
void Try(int i) {
    if (fixed_val[i]) {
        if (i == N) printResult();
        else Try(i + 1);
        return; 
    }
    for (int j = 1; j <= N; ++j) {
        if (!used[j]) { // nếu j chưa được chọn
            X[i] = j;      // Thử đặt X[i] = j
            used[j] = true; // used

            if (i == N) printResult(); 
            else Try(i+1);

            used[j] = false; //khôi phục trạng thái
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N>>k;

    int xung_dot= 0;
    fixed_val.assign(N + 1, 0);
    X.assign(N + 1, 0);
    used.assign(N + 1, 0);

    for (int i=0;i<k;i++){
        int u,v;
        cin>> u>>v;
        
        if (xung_dot) continue;
        if (fixed_val[u]) {
            if (X[u] != v) xung_dot = 1;
        }
        else {
            if (used[v]) xung_dot = 1;
            else {
                fixed_val[u] = 1;
                X[u] = v;
                used[v] = 1;
            }
        }
    }

    if(xung_dot){
        cout<<"0\n";
        return 0;
    }
    Try(1);
    if (!ok) cout<<"0\n";
    return 0;
}
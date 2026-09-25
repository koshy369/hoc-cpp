#include <iostream>
#include <vector>
#define boost ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int N;
string X;
string x1;
vector<bool> used;

void printResult() {
    for (int i = 1; i <= N; ++i) {
        cout << x1[i];
    }
    cout << " ";
}

void Try(int i) {
    for (int v = 0; v < N; ++v) {
        if (!used[v]) {
            x1[i] = X[v];     
            used[v] = true; 

            if (i == N) {
                printResult(); 
            } else {
                Try(i + 1);  
            }

            used[v] = false;
        } 
    } 
}

int main() {
    boost
    int t; cin>>t;
    while(t--){
        
        cin>>X;
        N=X.length();

        x1.assign(N,'0');
        used.assign(N + 1, false);

        Try(1); // Bắt đầu điền từ vị trí thứ 1
        cout << "\n";
    }
    return 0;
}
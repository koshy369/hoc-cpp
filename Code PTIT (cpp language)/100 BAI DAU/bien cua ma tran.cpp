
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n ;
    int a[n][n];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(i==n-1||j==n-1||i==0|| j==0){
                cout << a[i][j] << " ";
            }
            else {
                cout << "  ";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
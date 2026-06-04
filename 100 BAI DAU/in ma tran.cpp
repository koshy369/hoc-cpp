
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
        if(i%2==0){
            for (int j = 0; j < n; j++){
                cout << a[i][j] << " ";
            }
        }
        else {
            for (int j = n-1; j >=0 ; j--){
                cout << a[i][j] << " ";
            }
        }
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
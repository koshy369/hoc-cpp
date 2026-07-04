
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve() {
    int n; cin >> n ;
    int a[n][3];
    int sum=0;
    for (int i = 0; i < n; i++){
        int so1=0, so0=0;
        for (int j = 0; j <3; j++){
            cin >> a[i][j];
            if (a[i][j]==1) so1++;
            else so0++;
        }
        if(so1>so0) sum++;
    }
    cout <<sum<< endl;
}

int main() {
		solve();
    return 0;
}
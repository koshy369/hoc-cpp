#include <bits/stdc++.h>

using namespace std;

int n = 8, k;
int a[15];
int cnt;

void backtrack(int i, int s){
    if(cnt == k) return;
    if(s > 10) return;
    if(i == n + 1){
        if(s != 10) return;
        cnt++;
        if(cnt == k){
            bool nonzero = false;
            for(int j = 1; j <= n; j++){
                if(a[j] != 0 && !nonzero) nonzero = true;
                if(nonzero) cout << a[j];
            }
        }
        return;
    }

    for(int j = 0; j <= 9; j++){
        a[i] = j;
        backtrack(i + 1, s + j);
        a[i] = -1;
    }
}


int main(){
    cin >> k;
    for(int i = 1; i <= n; i++) a[i] = -1;
    backtrack(1, 0);

    return 0;
}

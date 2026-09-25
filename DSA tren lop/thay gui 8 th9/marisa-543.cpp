#include <bits/stdc++.h>

using namespace std;

int n;
int a[15];

void backtrack(int i){
    if(i == n + 1){
        for(int j = 1; j <= n; j++){
            cout << a[j];
        }
        cout << endl;
        return;
    }

    a[i] = 0;
    backtrack(i + 1);
    a[i] = -1;

    a[i] = 1;
    backtrack(i + 1);
    a[i] = -1;
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = -1;
    backtrack(1);

    return 0;
}

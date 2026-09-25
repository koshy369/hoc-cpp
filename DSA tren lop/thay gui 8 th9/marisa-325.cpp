#include <bits/stdc++.h>

using namespace std;

int n;
int a[15];
bool used[15];

void backtrack(int i){
    if(i == n + 1){
        for(int j = 1; j <= n; j++){
            cout << a[j] << " ";
        }
        cout << endl;
        return;
    }

    for(int j = 1; j <= n; j++){
        if(!used[j]){
            a[i] = j;
            used[j] = true;
            backtrack(i + 1);
            a[i] = -1;
            used[j] = false;
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++) a[i] = -1;
    backtrack(1);

    return 0;
}

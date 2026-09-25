#include <bits/stdc++.h>

using namespace std;

int n, k;
int a[25];
int state = 0;

void backtrack(int i){
    if(i == n + 1){
        //state++;
        int cnt1 = 0;
        for(int j = 1; j <= n; j++){
            if(a[j] == 1) cnt1++;
        }
        if(cnt1 != k) return;
        for(int j = 1; j <= n; j++){
            if(a[j] == 1) cout << j << " ";
        }
        cout << endl;
        return;
    }

    a[i] = 1;
    backtrack(i + 1);
    a[i] = -1;

    a[i] = 0;
    backtrack(i + 1);
    a[i] = -1;
}

int main(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) a[i] = -1;
    backtrack(1);
    //cout << "state = " << state << endl;

    return 0;
}





#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, p;
    cin >> n >> m >> p;
    
    long long cnt = 0;
    if (p <= n) {
        cnt = (n - p) / m + 1;
    }
    
    long long t = cnt + 1;
    
    cout << t;
    
    return 0;
}
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--){
        int n, a[100], ok = 1;
        cin >> n;
        for(int i = 1; i <= n; i++) a[i] = 0;
        while(ok) {
            for(int i = 1; i <= n; i++) cout << a[i];
            cout <<" ";
            int i = n;
            while(i >= 1 && a[i] == 1) {
                a[i] = 0;
                i--;
            }
            if(i == 0) ok = 0;
            else a[i] = 1;
        }
        cout<<endl;
    }
    return 0;
}
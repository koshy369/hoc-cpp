#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>
using namespace std;
typedef long long ll;
bool snto(long long n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}
int dem=0;
void SoGiam(int n, int index, int startDigit,int kqua) {
    if (index == n) {
        if(snto(kqua)) dem++;
        return;
    }
    for (int i = startDigit; i >= 0; i--) {
        SoGiam(n, index +1, i-1,kqua*10+i);
    }
}
void SoTang(int n, int index, int startDigit,int kqua) {
    if (index ==n) {
        if(snto(kqua)) dem++;
        return;
    }
    for (int i = startDigit; i<=9; i++) { 
        SoTang(n, index+1, i + 1,kqua*10+i);
    }
}
void solve(){
	long long a;
	cin >>a;
	dem=0;
	SoGiam(a,0,9,0);
	SoTang(a,0,1,0);
	cout<<dem<<endl;
	return;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int test;
	cin >>test;
	while (test--){
		solve();
	}	
    return 0;
}

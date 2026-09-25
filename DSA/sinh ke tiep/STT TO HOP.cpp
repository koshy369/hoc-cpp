#include <bits/stdc++.h>
using namespace std;
int sl=15;
int n,m,dem=0;
vector<int>  a;
vector<vector<long long>> C(sl+1, vector<long long>(sl+1, 0));
// to hop chap j cua i;
void TienXuLy(){
     for (int i = 0; i <= sl; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
        }
    }
}

int solve() {
	long long sum =1;
    int prep=0;
    for(int i=0; i<m; i++){
        int so =a[i];
    	for(int j=prep +1 ; j< so; j++){
            sum+=C[n-j][m-1-i];
        }
        prep=so;
	}
	return sum;
}

int main() {
	TienXuLy();
	int t; cin>>t;
    while(t--){
		cin>>n>>m;
		a.assign(m,0);
		for (int i=0 ; i<m ; i++ ){
			cin>>a[i];
		}
		cout<<solve()<<"\n";
	}
    
}
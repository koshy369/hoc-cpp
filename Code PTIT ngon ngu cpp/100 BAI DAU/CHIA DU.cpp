#include <iostream>
using namespace std;
void solve(){
	int a,b;
	cin >>a>>b;
	for (int i=0;i<b;i++){
		if (a*i%b==1){
			cout << i << endl;
			return;
		}	
	}
	cout << -1 << endl;
}
int main()
{
	int test;
	cin >>test;
	while (test--){
		solve();
	}
    return 0;
}
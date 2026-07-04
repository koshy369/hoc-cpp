
#include <iostream>
#include <vector> // dung cho vector
#include <algorithm> // dung cho sort
using namespace std;
void tachso(int i,int k[]){
	if (i==0) k[0]++;
	while(i>0){
		int so=i%10;
		i/=10;
		k[so]++;
	}
}
void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	int b[10]={0};
	for (int i = 0; i < n; i++){
		cin >> a[i];
		tachso(a[i],b);
		
	}
	for (int i = 0; i <10; i++) {
		if(b[i]>0) cout<< i<<" ";
	}
	cout<<endl;
}
int main() {
	int test;
	cin >> test;
	while (test--) {
		solve();
	}
    return 0;
}
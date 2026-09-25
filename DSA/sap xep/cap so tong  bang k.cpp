#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define db double
#define maxN 100005
#define vl vector<ll>
#define vi vector<int>
#define vb vector<bool>
#define ml map<ll,int>
#define pb push_back
#define pob pop_back
#define vpii vector<pair<int,int>>
#define boost ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

using namespace std;

int n,m,k,sum,ok=0,test;
vector<ll>a;

void Try(int start, int m){
	auto it = lower_bound(a.begin() + start, a.end(),k-m);
	if(it != a.end()){
		int index= it -a.begin();
		if(a[index] + m==k) sum++;
		Try(index + 1, m);
	}
	else return;
}
int main(){
	boost;
	cin>>test;
	while(test--){
		cin>>n>>k;
		a.assign(n,0);

		for(int i=0; i<n; i++){
			cin>>a[i];
		}
		sort(a.begin(), a.end());

		sum = 0;

		for(int i=0; i<n;i++){
			auto it = lower_bound(a.begin() + i + 1, a.end(),k - a[i]);
			if(it != a.end()){
				int index= it -a.begin();
				if(a[it -a.begin()]+a[i]==k) sum++;
				Try(index + 1, a[i]);
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
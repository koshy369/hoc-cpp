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
vector<ll>a,b;
string s;

int main(){
	boost;
	cin>>test;
	while(test--){
		cin>>n;
		b.assign(n,0);

		for(int i=0; i<n; i++){
			cin>>b[i];
		}
		sort(b.begin(), b.end());

		int dau=0, cuoi=n-1;
		
		ll ans=b[dau] + b[cuoi];
		ll min_absSum =abs(ans);
		int dap_an=0;

		while(dau< cuoi){
			int t=b[dau]+b[cuoi];
			int at= abs(t);
			if(at< min_absSum ){
				min_absSum=at;
				ans =t;
				dap_an =0;
			}
			else if(at== min_absSum) dap_an++;
			if(t<0) dau++;
			else if(t>0) cuoi--;
			else break;
		}
		if(dap_an>1) cout<<"-1"<<"\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
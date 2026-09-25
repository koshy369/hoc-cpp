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
		a.clear();
		b.assign(10,0);

		for(int i=0; i<n; i++){
			cin>>s;
			for(auto c: s){
				b[c-'0']=1;
			}
		}
		for(int i=0; i< 10;i++){
			if(b[i]==1) a.push_back(i);
		}
		sum = 0;

		for(auto x : a){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
	return 0;
}
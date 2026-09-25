#include <bits/stdc++.h>
using namespace std;
int n,dem=0,ok=0,m;
string  a;
vector<long long> luu;
#include <queue>
#include <vector>

void generate_90() {
    queue<long long> q;
    q.push(9);
    
    while (!q.empty()) {
        long long current = q.front();
        q.pop();
        
        if (current > 900000000000000000LL) break;
        luu.push_back(current);
        
        // Sinh ra 2 số tiếp theo
        q.push(current * 10);
        q.push(current * 10 + 9); 
    }
}
int main() {
	int n=1;
	generate_90();
    int t; cin>>t;
    while(t--){
    	cin>>m;
    	for (auto x : luu){
        	if (x%m==0){
				cout<<x<<"\n";
				break;
			}
    	}
    }
}

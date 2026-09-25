#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<int> a,b;

bool next_to_hop() {
    for (int i = k - 1; i >= 0; --i) {
        
        if(a[i]!= n-k+i+1){//chua max
            a[i]++;
            int c = a[i];
            for (int j = i + 1; j < k; ++j) { 
                a[j] = ++ c;            }
            return true;
        }
    }
    return false; 
}

int main() {
    int t; cin>>t;
    while(t--){
		int ok=0;
        cin>>n>>k;
        a.assign(k,0);
        for (int i=0; i<k; i++){
            cin>>a[i];
        }
		b=a;
		ok= next_to_hop();
		if(ok==0){
			cout <<k<<"\n";
			continue;
		}
		unordered_set<int> hop;
		for(int i=0;i<k;i++){
			hop.insert(a[i]);
			hop.insert(b[i]);
		}
		cout<<(int) hop.size()-k<<"\n";
    }
    return 0;
}
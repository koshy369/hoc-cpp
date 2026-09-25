#include <bits/stdc++.h>
using namespace std;
int n, k;
vector<char> a;
vector<int> a1;


bool next_to_hop() {
    for (int i = k - 1; i >= 0; --i) {
        
        if(a1[i]!= n-k+i){//chua max
            a1[i]++;
            int c = a1[i];
            for (int j = i + 1; j < k; ++j) { 
                a1[j] = ++ c;            }
            return true;
        }
    }
    return false; 
}

void in(){
    int ok=0;
    cin>>n>>k;
    a.clear();
    set<string> s;

    for (char i='A'; i<'A'+n; i++){
        a.push_back(i);
    }
    n=(int)a.size();
    a1.assign(n,0);

    for (int i=0; i<k; i++){
        a1[i]= i;
    }
}
void out(){
    for(int i=0; i<k; i++){
        cout<<a[a1[i]];
    }
    cout<<"\n";
}

int main() {
    int t; cin>>t;
    while(t--){
        in();
        out();
        while(next_to_hop()){
            out();
        }
    }
    return 0;
}
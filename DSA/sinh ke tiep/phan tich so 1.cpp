#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n,m;
vector<long long>a;
void out(){
    cout<<"(";
    m=(int)a.size();
    for(int i=0;i<m; i++){
        cout<<a[i]<<((i==m-1)? ") " : " ");
    }
}
void analyze(int x, int j){

    for(int i=x;i>=1; i--){

        if(j>=i){
            a.push_back(i);

            if(j-i==0) out();
            else analyze(i,j-i);

            a.pop_back();
        }
    }
}

int main() {
    int t ; cin>>t;
    while (t--){
        cin>>n;
        a.clear();
        analyze(n,n);
        cout<<"\n";
    }
    return 0;
}
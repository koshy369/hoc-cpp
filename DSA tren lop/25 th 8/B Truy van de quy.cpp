#include<bits/stdc++.h>
#define vi vector<int>
using namespace std;
int n,m,c,b,d,l,r, OK=1,k,sum=0;
vi a,X;
#define max 1000000
int g[max],num[10][max];
int thu(int n){
    int tich=1;
    while(n>=1){
        int j =n%10;
        n/=10;
        if(j>0) tich*=j;
    }
    if (tich>9) thu(tich);
    else return tich;
}
int main(){
    ios::sync_with_stdio(false);
    for(int i=0; i< max; i++){
        g[i]=thu(i);
    }
    for(int j=1; j< 10; j++){
        num[j][0]=0;
        for(int i=1; i< max; i++){
            if(g[i]==j) num[i][j] = num[i][j-1]+1;
            else num[i][j] = num[i][j-1];
        }
    }
    cin>>c;
    while(c--){
        sum=0;
        cin>>l>>r>>k;
        cout<<num[k][r]-num[k][l-1]<<endl;
    }
    return 0;
}
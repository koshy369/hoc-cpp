#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void multiply(string& num, int x){ // nhan
    int carry=0;
    for(int i=0; i<(int)num.length(); i++){
        long prod =(num[i]-'0')*x +carry;
        carry = prod/10;
        num[i] = prod%10+'0';
    }
    while(carry){
        num+= (char)(carry%10+'0');
        carry/=10;
    }
}

void divide(string& res, int x) { // chia
    int rem=0;
    for(int  i= (int)res.length() - 1 ; i >= 0; i--){
        long long cur= rem*10 + res[i]-'0';
        res[i]= cur/x+'0';
        rem= cur % x;
    } 
    while(res.length()>1 && res.back()=='0') res.pop_back();
}

void xuat(string n){// in cuoi den dau
    for (int i =(int)n.length()-1; i>=0 ; --i) {
        cout << n[i];
    }
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n; n++;
    string res = "1";
    for (int i = 1; i <= n; i++){
        multiply(res, 4 * i - 2);
        divide(res, i + 1);
    }
    xuat(res);
    return 0;
}


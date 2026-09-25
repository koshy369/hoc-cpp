#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<double> d(13,0);
    int sum=0;
    for(int i=1;i<=6; i++){
        for (int j=i;j<=6; j++){
            cout<<i<<" + "<<j<< " = "<<j+i <<endl;
            d[i+j]++;
            sum++;
        }
    }
    cout<<" -----------------------" <<endl;
    for(int i=2;i<=12; i++){
        double xs=d[i]*100.0/sum;
        cout<<fixed<<setprecision(0)<<i<<": "<<d[i]<<"--"<<xs<<"%"<<endl;
    }
    return 0;
}
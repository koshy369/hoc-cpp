#include <iostream>
using namespace std;
int main()
{
    int test;
    cin >>test;
    long long f[94];
        f[0]=1;
        f[1]=1;
        for (int i=2;i<93;i++){
            f[i]=f[i-1]+f[i-2];
        }
    while(test--){
        int a;
        cin >>a;
        cout<<f[a-1]<<endl;
    }
    return 0;
}

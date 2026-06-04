#include <iostream>
using namespace std;
int main()
{
    long long a,sum=0,sum1=1;
    cin >>a;
    for (int i=1;i<=a;i++){
        sum1*=i;
        sum+=sum1;
    }
    cout<< sum<<endl;
    return 0;
}

#include <iostream>
using namespace std;
int main()
{
    char test;
    cin >>test;
    while(test--){
        char i;
        cin>> i;
        if(96<i && i<123) cout<< (char)(i-32)<< endl;
        else if(64<i && i<91) cout<< (char)(i+32)<< endl;
        else cout<<i<< endl;
    }
    return 0;
}

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int test;
    cin >>test;
    getchar();
    while(test--){
        string a, b;
        cin >>a;
        int len=a.length();
        int dem=0;
        for(int i=0;i<len;i++){
            if(a.substr(i,3)=="084"){
                i+=2;
                continue;
            }
            else{
                b.push_back(a[i]);
            }
        }
        cout<<b<<endl;
    }
    return 0;
}

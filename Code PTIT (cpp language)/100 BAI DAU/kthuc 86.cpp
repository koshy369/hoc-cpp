#include <iostream>
using namespace std;
int main()
{
    int test;
    cin >>test;
    while (test--){
        long long so;
        cin >>so;
        if (so % 100 == 86) {
            cout << "1" << endl;
        } else {
            cout << "0" << endl;
        }
    }
    return 0;
}

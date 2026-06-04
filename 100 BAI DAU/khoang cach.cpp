#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int test;
    cin >>test;
    while (test--){
        double a,b,x,y;
        cin >>a>>b>>x>>y;
        double khoangcach=sqrt((x - a) * (x - a) + (y - b) * (y - b));
        cout << fixed << setprecision(4) << khoangcach << endl;
    }
    return 0;
}

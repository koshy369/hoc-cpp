#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    double a, sum = 0;
    cin >> a;
    for (long long i = 1; i <= a; i++)
    {
        sum += 1.0 / i;
    }
    cout << fixed << setprecision(4) << sum;
    return 0;
}


#include <iostream>
using namespace std;

int pow(int x, int n)
{
    if (n == 0) return 1;
    int k = x;
    for (int i = 0; i < n; i++)
    {
        x *= k;
    }
    return x;
}

long double df(long double k) {
    if (k <= 1) return 1;
    else return k * df(k-2);
}

long double t (long double x) {
    long double first = 0, second = 0;
    for (int k = 0; k <= 10; k++) 
    {
        first += pow(x, 2*k+1)/ df(2*k+1);
        second += pow(x, 2*k)/ df(2*k);
    }
    return first/second;
}

int main() {

    long double y;
    cin >> y;

    long double result = (7 * t(0.25) + 2 * t(1 + y)) / (6 - t(pow(y, 2) - 1));

    cout << result << endl;

    return 0;
}
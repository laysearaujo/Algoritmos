#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int L;
    cin >> L;

    double H, A, V, Ab;

    H = L * sqrt(6);
    H /= 3;

    A = pow(L,2) * sqrt(3);

    Ab = A / 4;

    V = Ab * H;
    V /= 3;

    cout << setprecision(2) << fixed << H << ' ' << A << ' ' << V << endl;

    return 0;
}
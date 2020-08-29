#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int n, cont = 0;
    cin >> n;
    float note[n];
    double average, x;
    for (int i = 0; i < n; i++) {
        cin >> note[i];
        average += note[i];
    }
    average /= n;
    for(int i = 0; i < n; i++) {
        if(note[i] >= average) {
            cont++;
        }
    }

    x = (cont * 100);
    x /= n;
    cout << setprecision(2) << fixed << x << '%' << endl;

    return 0;
}
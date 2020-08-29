#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x = 0, y = 1, i = 0, f = 0, n;
    cin >> n;
    if (n == 2 || n == 3)
    {
        f = 1;
    }
    else if (n == 1)
    {
        f = 0;
    }
    else
    {
        for (i = 3; i <= n; i++)
        {
            f = x + y;
            x = y;
            y = f;
        }
    }

    cout << f << endl;
    return 0;
}

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    int numb1, numb2, result = 0, aux1, aux2;
    cin >> numb1;
    cin >> numb2;
    if (numb1 == 0 || numb2 == 0)
    {
        result = 0;
    }
    else if (numb1 < 0 || numb2 < 0)
    {
        aux1 = fabs(numb1);
        aux2 = fabs(numb2);
        for (int i = 0; i < aux2; i++)
        {
            result += aux1;
        }
        if ((numb1 < 0 && numb2 > 0) || (numb1 > 0 && numb2 < 0))
        {
            cout << '-';
        }
    }
    else
    {
        for (int i = 0; i < numb2; i++)
        {
            result += numb1;
        }
    }
    cout << result << endl;
    return 0;
}
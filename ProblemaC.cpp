// tá tudo errado - REFAZER!!!
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n, c, e, cres, dec;
    cin >> n;
    int val[n];

    cin >> val[0];
    for(int i = 0; i < n; i++) {
        cin >> val[i];
        if(val[i] > val[i--]) {
            cres++;  
        } else if (val[i] == val[i-1]) {
            e++;
        }else if (val[i] < val[i-1]) {
            dec++;
        } else {
            c++;
        }
    }

    if(e > 0) {
        cout << "ERRO" << endl;
        return 0;
    }

    if(cres > (dec && c) ) {
        cout << "PERMUTACAO CRESCENTE" << endl;
    } else if (dec > (cres && c)) {
        cout << "PERMUTACAO DECRESCENTE" << endl;
    } else {
        cout << "PERMUTACAO COMUM" << endl;
    }

    return 0;
}
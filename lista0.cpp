#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main () {
    int n;

    cin >> n;
    string word[n];
    for(int i = 0; i < n; i++) {
        cin >> word[i];
    }
    
    int i = 0;
    char str;
    while (cin >> str)
    {
        if (str != EOF) {
            if(str == '#') {
                i++;
                if(i == 10) {
                    i = 0;
                }
                cout << i;
            }
            if(str == 'X') {
                for(int i = 0; i < n; i++){
                    cout << word[i];
                }
            }
        } else
           return 0;
    }
    return 0;
}
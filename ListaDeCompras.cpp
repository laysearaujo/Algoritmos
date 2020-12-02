#include <bits/stdc++.h>

using namespace std;
int R = 0;

void unique(int l, int sum, int max, vector<int> local, vector<int> P, int min);
void combination(vector<int> P, int Q, int M);

int main()
{
    int k, L, M, Q, price;
    vector<int> P;
    cin >> k;

    for (int i = 0; i < k; i++)
    {
        cin >> L;
        for (int j = 0; j < L; j++)
        {
            cin >> price;
            P.push_back(price);
        }
        cin >> M >> Q;
        combination(P, Q, M);
        cout << "caso " << i << ": " << R << endl;
        P.clear();
        R = 0;
    }
    return 0;
}

void unique(int l, int sum, int max, vector<int>& local, vector<int>& P, int min)
{
    if (sum <= max)
    {
        if (local.size() >= min)
        {
            R++;
        }
    }

    for (int i = l; i < P.size(); i++)
    {
        if (sum + P[i] > max)
        {
            continue;
        }

        local.push_back(P[i]);
        unique(i + 1, sum + P[i], max, local, P, min);
        local.pop_back();
    }
}

void combination(vector<int> P, int Q, int M)
{
    sort(P.begin(), P.end());
    vector<int> local;
    unique(0, 0, Q, local, P, M);
    local.clear();
}
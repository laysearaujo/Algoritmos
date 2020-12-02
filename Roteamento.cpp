#include <bits/stdc++.h>
using namespace std;

#define inf 100000000

typedef pair<int, int> iPair;
int tam = 0, dr, sum = 0;
int matriz[10000][10000];

void sumBand(int aux, int *parents, int size)
{
    tam++;
    if (parents[aux] == -1)
        return;
    sum += (size / matriz[aux][parents[aux]]);
    aux = parents[aux];
    sumBand(aux, parents, size);
}

void addEdge(vector<pair<int, int>> adj[], int u, int v, int wt)
{
    adj[u].push_back(make_pair(v, wt));
    adj[v].push_back(make_pair(u, wt));
}

int *shortestPath(vector<pair<int, int>> adj[], int n, int origin, int destiny)
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    vector<int> dist(n, inf);
    int *parents = new int[n];
    parents[dr] = -1;

    pq.push(make_pair(0, dr));
    dist[dr] = 0;

    while (!pq.empty())
    {
        int min = pq.top().second;
        int x = pq.top().first;
        pq.pop();

        if (x > dist[min])
            continue;
        for (auto x : adj[min])
        {
            int v = x.first;
            int weight = x.second;

            if (dist[v] > dist[min] + weight)
            {
                dist[v] = dist[min] + weight;
                parents[v] = min;
                pq.push(make_pair(dist[v], v));
            }
            else if (dist[v] == dist[min] + weight)
            {
                if (min < parents[v])
                {
                    parents[v] = min;
                }
            }
        }
    }
    return parents;
}

int main()
{
    int n, aux, id, band, m, emitter, receiver, caso = 0, size;

    while (cin >> n)
    {
        cin >> dr;
        vector<iPair> adj[n];
        int *parents = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            for (int j = 0; j < aux; j++)
            {
                cin >> id;
                cin >> band;
                matriz[i][id] = band;
                addEdge(adj, i, id, (pow(2, 20) / band));
            }
        }

        parents = shortestPath(adj, n, emitter, receiver);
        
        cin >> m;
        cout << "caso " << caso << ":" << endl;
        for (int i = 0; i < m; i++)
        {
            cin >> emitter;
            cin >> receiver;
            cin >> size;

            int aux = emitter;
            sumBand(aux, parents, size);
            aux = receiver;
            sumBand(aux, parents, size);

            cout << tam - 3 << " " << sum << endl;
            tam = 0;
            size = 0;
            sum = 0;
        }
        caso++;
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
#define MAX(a, b) (a > b ? a : b)
#define MIN(a, b) (a < b ? a : b)
using namespace std;

template <class T>
inline vector<T> &operator+(vector<T> &a, vector<T> b)
{
    a.insert(a.end(), b.begin(), b.end());
    return a;
}
template <class T>
inline ostream &operator<<(ostream &os, const vector<T> &v)
{
    if (!v.size())
        os << "[]";
    else
    {
        os << "[";
        for (int i = 0; i < v.size(); i++)
            os << v[i] << (i + 1 == v.size() ? "]" : ", ");
    }
    return os;
}

typedef vector<vector<int>> G;

void Insert(G &graph, G &weights, int a, int b, int w)
{
    graph[a].push_back(b);
    weights[a][b] = w;
}

// ESTUDAR ESSA FUNÇÃO !!!
void find_all_paths(G &all_paths, vector<int> current_path, G &parents, int current_node)
{
    if (current_node == -666)
        all_paths.push_back(current_path);
    else
    {
        for (auto v : parents[current_node])
        {
            current_path.push_back(current_node);
            find_all_paths(all_paths, current_path, parents, v);
            current_path.pop_back();
        }
    }
}
// ESTUDAR ESSA FUNÇÃO !!!

void print_queue(queue<int> q)
{
    cout << "===================================" << endl;
    cout << "Estado fila: [";
    while (!q.empty())
    {
        cout << q.front() << (q.size() == 1 ? "" : ", ");
        q.pop();
    }
    cout << "]" << endl;
    cout << "===================================" << endl;
}

vector<long> Dijkstra(G &graph, G &weights, int S, int T)
{
    vector<long> dist(10, INT_MAX); // simula o infinito
    G parents(10);
    parents[S].push_back(-666);
    dist[S] = 0;
    queue<int> q;
    q.push(S);
    while (!q.empty())
    {
        print_queue(q);
        int u = q.front();
        q.pop();
        cout << "Visitando " << u << endl;
        for (auto v : graph[u])
        {
            cout << "Vizinho de " << u << ": " << v << endl;
            if (dist[v] > dist[u] + weights[u][v])
            { // menor caminho encontrado
                cout << "Novo menor caminho encontrado" << endl;
                dist[v] = dist[u] + weights[u][v];
                parents[v].clear();      // limpamos todo o caminho anterior encontrado
                parents[v].push_back(u); // colocamos o novo menor cainho
                q.push(v);
            }
            else if (dist[v] == dist[u] + weights[u][v])
            {
                cout << "Novo potencial menor caminho por: " << u << endl;
                parents[v].push_back(u); // novo potencial menor caminho
            }
        }
    }
    // parents -> Grafo com todos os precursores, tarefa de casa encontrar uma maneira de fazer os caminhos
    G all_paths;
    vector<int> temp;
    find_all_paths(all_paths, temp, parents, T);
    for (int i = 0; i < parents.size(); i++)
        cout << "No " << i << ": precursores: " << parents[i] << endl;
    return dist;
}

int main()
{
    G graph(10), weights(10);
    for (int i = 0; i < 10; i++)
        weights[i].resize(10);
    Insert(graph, weights, 0, 1, 1);
    Insert(graph, weights, 0, 2, 5);
    Insert(graph, weights, 0, 4, 8);
    Insert(graph, weights, 1, 3, 2);
    Insert(graph, weights, 2, 5, 5);
    Insert(graph, weights, 3, 4, 4);
    Insert(graph, weights, 3, 6, 9);
    Insert(graph, weights, 4, 7, 1);
    Insert(graph, weights, 4, 5, 2);
    Insert(graph, weights, 5, 8, 1);
    Insert(graph, weights, 7, 6, 2);
    Insert(graph, weights, 8, 7, 3);
    int index = 0;
    for (int i = 0; i < graph.size(); i++)
        cout << "No " << i << ": vizinhos: " << graph[i] << endl;
    vector<long> dists = Dijkstra(graph, weights, 0, 8);
    cout << "Vetor de distancias: " << dists << endl;
    return 0;
}
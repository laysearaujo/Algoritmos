#include <iostream>
#include <string>
#include <math.h>

#define inf 100000000;

typedef struct node
{
    int id = inf;
    int band = inf;
    int c = inf;
    struct node *next;
} node;

using namespace std;

int sum = 0, tam = 0;

node *init(int id, int band);
node *list_isert(node *list, int id, int band);
int min_distanceIndex(bool *M, int *D, int n);
int *Dijkstra(node **list, int n, int size, int dr);
int list_cur(node *list, int id);

void sumBand(int aux, int *parents, int size)
{
    tam++;
    if (parents[aux] == -1)
        return;
    sum += (size / matriz[aux][parents[aux]]);
    aux = parents[aux];
    sumBand(aux, parents, size);
}

int Vetor[10000000];
int matriz[10000][10000];
int tam = 0;

int main()
{
    int n, aux, dr, id, band, m, emitter, receiver, T1, T2, caso = 0, aux1, aux2, size;

    while (cin >> n)
    {
        cin >> dr;
        node *list[n];
        int *parents = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> aux;
            for (int j = 0; j < aux; j++)
            {
                cin >> id;
                cin >> band;
                if (j == 0)
                {
                    list[i] = init(0, 0);
                }
                list[i] = list_isert(list[i], id, band);
                matriz[i][id] = band;
            }
        }

        cin >> m;
        parents = Dijkstra(list, n, size, dr);
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
            sum = 0;
        }
        caso++;
        cout << endl;
    }

    return 0;
}

node *init(int id, int band)
{
    node *aux = new node();
    aux->id = id;
    aux->band = band;
    aux->next = NULL;

    return aux;
}

node *list_isert(node *list, int id, int band)
{
    node *cur = list;
    node *N = new node();
    N->id = id;
    N->band = band;

    N->c = (pow(2, 20) / band);
    N->next = NULL;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = N;
    return list;
}

int list_cur(node *list, int id)
{
    int aux;
    while (list->next != NULL)
    {
        if (list->next->id == id)
        {
            aux = list->next->band;
            return aux;
        }
        list = list->next;
    }
    return 0;
}

int min_distanceIndex(bool *M, int *D, int n)
{
    int index = 0;
    int aux = inf;

    for (int i = 0; i < n; i++)
    {
        if (M[i] == false && D[i] < aux)
        {
            index = i;
            aux = D[i];
        }
    }
    return index;
}

int *Dijkstra(node **list, int n, int size, int dr)
{
    int D[n], P[n], min, dist, soma = 0;
    int *parents = new int[n];
    int v, w, peso = 0;
    bool M[n];

    for (int i = 0; i < n; i++)
    {
        D[i] = inf;
        P[i] = -1;
        M[i] = false;
    }

    for (int i = 0; i < n; i++)
    {
        min = min_distanceIndex(M, D, n);
        dist = D[min];
        M[min] = true;

        node *cur = list[min];
        if (i < D[dist])
            continue;
        while (cur->next != NULL)
        {
            v = cur->next->id;
            w = cur->next->c;

            if (dist + w < D[v] && M[v] == false)
            {
                D[v] = dist + w;
                P[v] = min;
            }
            else if (dist + w == D[v])
            {
                if (P[v] > min)
                {
                    P[v] = min;
                }
            }
            cur = cur->next;
        }
    }

    parents = P;
    return P;
}

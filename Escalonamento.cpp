#include <iostream>

using namespace std;

typedef struct node
{
    int id = 0;
    int time = 0;
    int timeTotal = 0;
} node;

#define inf 100000000

node *createHeap(int tamHeap);
void insert(node *h, int id, int time, int timeTotal);
void heapify_bottom_top(node *h, int index);
void heapify_top_bottom(node *h, int parent_node);
node popMin(node *h);

int heapSize = 0;
int capacity = 0;
int tamP = 0;

int main()
{
    int P, S;
    int ter[1000], newP[1000], queue[1000], get[1000];
    string command;
    node *heap, *wait = new node[1000000];
    int id, auxW = 0;
    bool *M = new bool[1000000];
    int C = 0, I = 0, A = 0, D = 0, R = 0, G = 0;

    cin >> P >> S;

    node processor[P];
    for (int i = 0; i < P; i++)
    {
        processor[i].id = -1;
        processor[i].time = inf;
        processor[i].timeTotal = inf;
    }
    int contP = 0;

    heap = createHeap(10000000);

    do
    {
        cin >> command;

        if (command == "NEW")
        {
            cin >> id;
            A++;
            newP[A] = id;
        }
        if (command == "TER")
        {
            cin >> id;
            C++;
            ter[C] = id;
        }
        if (command == "REQ")
        {
            cin >> id;
            R++;
            M[id] = true;

            // cout << M[id] << endl;
        }
        if (command == "GRT")
        {
            cin >> id;
            G++;
            get[G] = id;
        }
        if (command == "SCH")
        {

            for (int i = 0; i < P; i++)
            {
                processor[i].time++;
                processor[i].timeTotal++;
            }

            // cout << "depois" << endl;
            // for (int i = 0; i < P; i++)
            // {
            //     cout << processor[i].id << "|" << processor[i].time << " ";
            // }

            // C
            if (C > 0)
            {
                int aux = C;
                while (aux > 0)
                {
                    for (int i = 0; i < P; i++)
                    {
                        if (ter[aux] == processor[i].id)
                        {
                            ter[aux] = -1;
                            processor[i].id = -1;
                            processor[i].time = inf;
                            processor[i].timeTotal = inf;
                        }
                    }
                    aux--;
                }
            }

            // R
            if (R > 0)
            {
                for (int i = 0; i < P; i++)
                {
                    if (M[processor[i].id] == true)
                    {
                        // cout << "entrei" << endl;
                        wait[processor[i].id].id = processor[i].id;
                        wait[processor[i].id].time = 0;
                        wait[processor[i].id].timeTotal = processor[i].timeTotal;
                        auxW++;
                        processor[i].id = -1;
                        processor[i].time = inf;
                        processor[i].timeTotal = inf;
                    }
                }
            }

            // I
            for (int i = 0; i < P; i++)
            {
                if (processor[i].time == S)
                {
                    insert(heap, processor[i].id, 0, processor[i].timeTotal);
                    processor[i].id = -1;
                    processor[i].time = inf;
                    processor[i].timeTotal = inf;
                    I++;
                }
            }

            // G
            if (G > 0)
            {
                int aux = G;
                while (aux != 0)
                {
                    
                    if (wait[get[aux]].id == get[aux])
                    {
                        // cout << get[aux] << endl;
                        M[get[aux]] = false;
                        insert(heap, wait[get[aux]].id, inf, wait[get[aux]].timeTotal);
                        wait[get[aux]].id = -500;
                        get[aux] = -500;
                    }
                    aux--;
                }
            }

            // A
            if (A > 0)
            {
                int aux = A;
                while (aux > 0)
                {
                    insert(heap, newP[aux], 0, 0);
                    aux--;
                }
            }

            // D
            for (int i = 0; i < P; i++)
            {
                if (processor[i].id == -1 && heapSize > 0)
                {
                    node aux = popMin(heap);
                    processor[i].id = aux.id;
                    processor[i].time = 0;
                    processor[i].timeTotal = aux.timeTotal;
                    D++;
                    tamP++;
                }
            }

            cout << C << " ";
            cout << I << " ";
            cout << R << " ";
            cout << G << " ";
            cout << A << " ";
            cout << D << endl;

            C = 0, I = 0, A = 0, D = 0, R = 0, G = 0;
        }

    } while (command != "END");

    return 0;
}

node *createHeap(int tamHeap)
{
    node *h = new node[tamHeap];

    heapSize = 0;
    capacity = tamHeap;
    return h;
}

void insert(node *h, int id, int time, int timeTotal)
{
    if (heapSize < capacity)
    {
        h[heapSize].id = id;
        h[heapSize].time = time;
        h[heapSize].timeTotal = timeTotal;
        heapify_bottom_top(h, heapSize);
        heapSize++;
    }
}

void heapify_bottom_top(node *h, int index)
{
    node temp;
    int parent_node = (index - 1) / 2;

    if ((h[parent_node].timeTotal > h[index].timeTotal) || (h[parent_node].timeTotal == h[index].timeTotal && h[parent_node].id > h[index].id))
    {
        temp = h[parent_node];
        h[parent_node] = h[index];
        h[index] = temp;
        heapify_bottom_top(h, parent_node);
    }
}

void heapify_top_bottom(node *h, int parent_node)
{
    int left = parent_node * 2 + 1;
    int right = parent_node * 2 + 2;
    int min;
    node temp;

    if (left >= heapSize || left < 0)
        left = -1;
    if (right >= heapSize || right < 0)
        right = -1;

    if (left != -1 && ((h[left].timeTotal < h[parent_node].timeTotal) || (h[left].timeTotal == h[parent_node].timeTotal && h[left].id < h[parent_node].id)))
        min = left;
    else
        min = parent_node;
    if (right != -1 && ((h[right].timeTotal < h[min].timeTotal) || (h[right].timeTotal == h[min].timeTotal && h[right].id < h[min].id)))
        min = right;

    if (min != parent_node)
    {
        temp = h[min];
        h[min] = h[parent_node];
        h[parent_node] = temp;

        heapify_top_bottom(h, min);
    }
}

node popMin(node *h)
{
    node pop;
    if (heapSize == 0)
    {
        node aux;
        aux.id = -1;
        aux.time = 0;
        aux.timeTotal = 0;
        return aux;
    }
    pop = h[0];
    h[0] = h[heapSize - 1];
    heapSize--;
    heapify_top_bottom(h, 0);
    return pop;
}

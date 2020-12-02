#include <iostream>

using namespace std;

typedef struct node
{
    long long user = 0;
    long long chanel = 0;
    int score = 0;
    struct node *next;
} node;

typedef struct chanels
{
    long long chanel = 0;
    int size = 0;
    struct chanels *next;
} chanels;

node *init(long long user, long long C, int S);
chanels *initChanel(long long C, int size);

int list_cur(node *list, long long U, long long C, int score);
int list_curScore(node *list, long long U, long long C);
int list_curChanel(chanels *list, long long C);
int list_curChanelSub(chanels *list, long long C);
int list_curChanelSize(chanels *list, long long C);

node *list_isert(node *list, long long U, long long C, int S);
chanels *list_isertChanel(chanels *list, long long C);

void show(node *list, long long U);

int list_delete(node *list, long long U);

node *hashT[1051];
chanels *hashChanel[1051];

int hashF(long long x) { return __builtin_popcount(x) % 1051; }

int main()
{
    string command;
    long long user, chanel;
    int score, aux = 0, hasChanel = 0;

    for (int i = 0; i < 1051; i++)
    {
        hashT[i] = init(0, 0, 0);
        hashChanel[i] = initChanel(0, 0);
    }

    do
    {
        cin >> command;

        // Registra a assinatura do Canal, pelo Usuario com Score
        if (command == "SUB")
        {
            cin >> user;
            cin >> chanel;
            cin >> score;

            aux = list_cur(hashT[hashF(user)], user, chanel, score);

            if (aux != 0)
            {
                cout << aux << endl;
            }
            else
            {
                hashT[hashF(user)] = list_isert(hashT[hashF(user)], user, chanel, score);

                // Se existe canal ++
                hasChanel = list_curChanel(hashChanel[hashF(chanel)], chanel);
                // Se não cria e ++
                if (hasChanel == 0)
                {
                    hashChanel[hashF(chanel)] = list_isertChanel(hashChanel[hashF(chanel)], chanel);
                }
                cout << score << endl;
            }
        }

        // Retorna lista de canais assinados pelo usuário U por ordem cornologica
        if (command == "CHN")
        {
            cin >> user;

            show(hashT[hashF(user)], user);
            //cout << 'c';
        }

        // Retorna quantidade de usuários inscritos no canal C
        if (command == "USR")
        {
            cin >> chanel;

            hasChanel = list_curChanelSize(hashChanel[hashF(chanel)], chanel);
            cout << hasChanel << endl;
        }

        // Retorna o Score dado pelo Usuário ao Canal -> S(U,C)
        if (command == "SCO")
        {
            cin >> user;
            cin >> chanel;

            aux = list_curScore(hashT[hashF(user)], user, chanel);
            cout << aux << endl;
        }

        // remove o usuário e imprime quantidade de canais assinados por ele
        if (command == "RMU")
        {
            cin >> user;

           aux = list_delete(hashT[hashF(user)], user);
           cout << aux << endl;
        }
    } while (command != "END");

    return 0;
}

node *init(long long U, long long C, int S)
{
    node *aux = new node();
    aux->chanel = C;
    aux->score = S;
    aux->next = NULL;

    return aux;
}
chanels *initChanel(long long C, int size)
{
    chanels *aux = new chanels();
    aux->chanel = C;
    aux->size = size;
    aux->next = NULL;

    return aux;
}

// Verefica os canais e retorna o score
int list_cur(node *list, long long U, long long C, int S)
{
    int aux;
    while (list->next != NULL)
    {
        if (list->next->chanel == C && list->next->user == U)
        {
            aux = list->next->score;
            list->next->score = S;
            return aux;
        }
        list = list->next;
    }
    return 0;
}
int list_curScore(node *list, long long U, long long C)
{
    int aux;
    while (list->next != NULL)
    {
        list = list->next;
        if (list->chanel == C && list->user == U)
        {
            aux = list->score;
            return aux;
        }
    }
    return 0;
}
int list_curChanel(chanels *list, long long C)
{
    while (list->next != NULL)
    {
        if (list->next->chanel == C)
        {
            list->next->size++;
            return 1;
        }
        list = list->next;
    }
    return 0;
}
int list_curChanelSub(chanels *list, long long C)
{
    while (list->next != NULL)
    {
        if (list->next->chanel == C)
        {
            list->next->size--;
            return 1;
        }
        list = list->next;
    }
    return 0;
}
int list_curChanelSize(chanels *list, long long C)
{
    int aux;
    while (list->next != NULL)
    {
        if (list->next->chanel == C)
        {
            aux = list->next->size;
            return aux;
        }
        list = list->next;
    }
    return 0;
}

node *list_isert(node *list, long long U, long long C, int S)
{
    node *cur = list;
    node *N = new node();
    N->user = U;
    N->chanel = C;
    N->score = S;
    N->next = NULL;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = N;
    return list;
}
chanels *list_isertChanel(chanels *list, long long C)
{
    chanels *cur = list;
    chanels *N = new chanels();
    N->chanel = C;
    N->size++;
    N->next = NULL;
    while (cur->next != NULL)
    {
        cur = cur->next;
    }
    cur->next = N;
    return list;
}

void show(node *list, long long U)
{
    int aux = 0;
    while (list->next != NULL)
    {
        list = list->next;
        if (list->user == U)
        {
            if (aux > 0)
            {
                cout << ' ';
            }
            cout << list->chanel;
            aux++;
        }
    }
    if (list->next == NULL && aux == 0)
    {
        cout << 0;
    }
    cout << endl;
}

int list_delete(node *list, long long U)
{
    int size = 0;
    int aux;
    long long chanel = 0;
    while (list->next != NULL)
    {   
        if(list->next->user == U) {
            chanel = list->next->chanel;
            aux = list_curChanelSub(hashChanel[hashF(chanel)], chanel);
            node *aux = list->next;
            list->next = aux->next;
            delete aux;
            size++;
        }else{
            list = list->next;
        }
    }

    return size;
}

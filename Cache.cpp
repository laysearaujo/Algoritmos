#include <iostream>

using namespace std;

typedef struct node
{
    long long value;
    struct node *right;
    struct node *left;
} node;

node *bst_search_father(node *root, long long value, node *aux);
node *bst_insert(node *root, long long value);
node *bst_search(node *root, long long value);
node *bst_delete(node *root, long long value);
node *bst_delete_min(node *root, node *aux);
node *splay(node *root, long long value);
node *right_rotate(node *root);
node *left_rotate(node *root);

void bst_show(node *root)
{
    if (root != NULL)
    {
        cout << root->value << ' ';
        bst_show(root->left);
        bst_show(root->right);
    }
}

int depth = 0;

int main()
{
    node *root = NULL;
    node *aux = NULL;

    int auxFather;
    string command;
    long long value;

    do
    {
        depth = 0;
        cin >> command;

        // Caso o X não seja encontrado, D deve correponder à
        // quantidade de nós visitados no caminho da raiz
        // até a folha percorrido pela consulta
        if (command == "FND")
        {
            cin >> value;
            aux = bst_search(root, value);

            if (aux == NULL)
            {
                // imprime o valor a profundida percorrida
                // para não encontrar o valor
                cout << depth << endl;
            }
            else
            {
                //imprime o valor ate encontrar o valor
                cout << depth << endl;
                // faz as rotações para ir para a raiz
                root = splay(root, value);
            }
        }

        if (command == "INS")
        {
            cin >> value;
            aux = bst_search(root, value);
            depth = 0;

            if (aux == NULL)
            {
                // insere na tree
                root = bst_insert(root, value);
                // busca profundidade
                aux = bst_search(root, value);
                cout << depth << endl;
                // faz rotação
                root = splay(root, value);
            }
            else
            {
                aux = bst_search(root, value);
                // imprimir a profundidade de value que
                cout << depth << endl;
                //já existe e faz as rotações para raiz
                root = splay(root, value);
            }
        }

        // profundidade do nó em que o elemento X for
        // originalmente encontrado na árvore antes de
        // qualquer modificação
        if (command == "DEL")
        {
            cin >> value;
            aux = bst_search(root, value);

            if (aux == NULL)
            {
                // imprime a quantidade de nós visitados
                // para não encontrar o valor (+1?)
                cout << depth << endl;
            }
            else
            {
                //imprime a profundidade ate encontrar o valor
                cout << depth << endl;
                // descobrir quem é o pai e mandar ele
                //essa função tá errada
                aux = bst_search_father(root, value, NULL);
                aux == NULL ? auxFather = 0 : auxFather = aux->value;
                // cout << auxFather << 'F' << endl;
                // deleta o nó
                root = bst_delete(root, value);
                // faz as rotações para o pai ir até a raiz
                root = splay(root, auxFather);
            }
        }

    } while (command != "END");

    return 0;
}

node *bst_insert(node *root, long long value)
{
    if (root == NULL)
    {
        node *n = new (node);
        n->value = value;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    else if (value < root->value)
    {
        root->left = bst_insert(root->left, value);
        return root;
    }
    else
    {
        root->right = bst_insert(root->right, value);
        return root;
    }
}

node *bst_search(node *root, long long value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (value == root->value)
    {
        return root;
    }
    else if (value < root->value)
    {
        depth++;
        return bst_search(root->left, value);
    }
    else
    {
        depth++;
        return bst_search(root->right, value);
    }
}

node *bst_delete(node *root, long long value)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (value < root->value)
    {
        root->left = bst_delete(root->left, value);
        return root;
    }
    else if (root->value < value)
    {
        root->right = bst_delete(root->right, value);
        return root;
    }
    else
    {
        if (root->left == NULL)
        {
            node *r = new (node);
            r = root->right;
            delete root;
            return r;
        }
        else if (root->right == NULL)
        {
            node *r = new (node);
            r = root->left;
            delete root;
            return r;
        }
        else
        {
            node *aux = new (node);
            root->right = bst_delete_min(root->right, aux);
            root->value = aux->value;
            return root;
        }
    }
}

node *bst_delete_min(node *root, node *aux)
{
    node *v;
    if (root->left == NULL)
    {
        aux->value = root->value;
        v = root->right;
        free(root);
        return v;
    }
    else
    {
        aux->value = root->value;
        root->left = bst_delete_min(root->left, aux);
        return root;
    }
}

node *bst_search_father(node *root, long long value, node *aux)
{

    if (root == NULL)
    {
        // não tá na árvore ou não tem pai
        return NULL;
    }
    else if (value == root->value)
    {
        // tem pai e retorna o valor desse pai
        return aux;
    }
    else if (value < root->value)
    {
        aux = root;
        return bst_search_father(root->left, value, aux);
    }
    else
    {
        aux = root;
        return bst_search_father(root->right, value, aux);
    }
}

node *right_rotate(node *root)
{
    node *y = root->left;
    root->left = y->right;
    y->right = root;
    return y;
}

node *left_rotate(node *root)
{
    node *y = root->right;
    root->right = y->left;
    y->left = root;
    return y;
}

// essa rotação tá errada temos que pegar do pai e rotacionar com ele
node *splay(node *root, long long value)
{
    node *aux;
    // casos base -> árvore vazia ou value na raiz
    if (root == NULL || root->value == value)
        return root;

    // esquerda
    if (value < root->value )
    {
        root->left = splay(root->left, value);
        root = right_rotate(root);
        return root;
    }
    else // direita
    {
        root->right = splay(root->right, value);
        root = left_rotate(root);
        return root;
    }
}

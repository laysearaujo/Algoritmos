#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cont = 0;
int c = 0;

typedef struct node
{
    int valor;
    struct node *right;
    struct node *left;
} node;

node *bst_insert(node *root, int valor);
void bst_show(node *root);
int height(node *root);
int MAX(int a, int b);
void pre_order(node *root);
node *bst_search(node *root, int valor);
node *bst_delete(node *root, int valor);
node *bst_delete_min(node *root, node *aux);

int main(void)
{

    node *root = NULL;
    node *aux;
    int n, valor, i, h, numb, prof;
    char op[3];

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {

        scanf("%d", &valor);
        root = bst_insert(root, valor);
    }
    //pre_order (root);
    //bst_show(root);
    h = height(root);

    printf("%i\n", h);
    scanf(" %s", op);

    while (strcmp(op, "END") != 0)
    {

        scanf("%d", &numb);
        cont = 0;
        c = 0;

        if (strcmp(op, "SCH") == 0)
        {
            aux = bst_search(root, numb);
            if (aux == NULL)
            {
                printf("-1\n");
            }
            else
            {
                prof = cont;
                printf("%i\n", prof);
            }
        }

        if (strcmp(op, "INS") == 0)
        {
            root = bst_insert(root, numb);
            aux = bst_search(root, numb);
            prof = c;
            printf("%i\n", prof);
        }

        if (strcmp(op, "DEL") == 0)
        {
            aux = bst_search(root, numb);
            if (aux == NULL)
            {
                printf("-1\n");
            }
            else
            {
                prof = cont;
                printf("%i\n", prof);
                root = bst_delete(root, numb);
            }
        }

        scanf(" %s", op);
    }
    h = height(root);
    printf("%i\n", h);
    //	bst_show (root);

    return 0;
}

node *bst_insert(node *root, int valor)
{
    if (root == NULL)
    {
        node *n = (node *)malloc(sizeof(node));
        n->valor = valor;
        n->left = NULL;
        n->right = NULL;
        return n;
    }
    else if (valor < root->valor)
    {
        c++;
        root->left = bst_insert(root->left, valor);
        return root;
    }
    else
    {
        c++;
        root->right = bst_insert(root->right, valor);
        return root;
    }
}

void bst_show(node *root)
{
    if (root != NULL)
    {
        printf("%i ", root->valor);
        bst_show(root->left);
        bst_show(root->right);
    }
}

int height(node *root)
{
    int l, r;
    if (root == NULL)
    {
        return 0;
    }
    else
    {
        l = height(root->left);
        r = height(root->right);
        return 1 + MAX(l, r);
    }
}

int MAX(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

void pre_order(node *root)
{
    if (root == NULL)
    {
        return;
    }
    pre_order(root->left);
    pre_order(root->right);
}

node *bst_search(node *root, int valor)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (valor == root->valor)
    {
        return root;
    }
    else if (valor < root->valor)
    {
        cont++;
        return bst_search(root->left, valor);
    }
    else
    {
        cont++;
        return bst_search(root->right, valor);
    }
}

node *bst_delete(node *root, int valor)
{
    if (root == NULL)
    {
        return NULL;
    }
    else if (valor < root->valor)
    {
        root->left = bst_delete(root->left, valor);
        return root;
    }
    else if (root->valor < valor)
    {
        root->right = bst_delete(root->right, valor);
        return root;
    }
    else
    {
        if (root->left == NULL)
        {
            node *r = (node *)malloc(sizeof(node));
            r = root->right;
            free(root);
            return r;
        }
        else if (root->right == NULL)
        {
            node *r = (node *)malloc(sizeof(node));
            r = root->left;
            free(root);
            return r;
        }
        else
        {
            node *aux = (node *)malloc(sizeof(node));
            root->right = bst_delete_min(root->right, aux);
            root->valor = aux->valor;
            return root;
        }
    }
}

node *bst_delete_min(node *root, node *aux)
{
    node *v;
    if (root->left == NULL)
    {
        aux->valor = root->valor;
        v = root->right;
        free(root);
        return v;
    }
    else
    {
        aux->valor = root->valor;
        root->left = bst_delete_min(root->left, aux);
        return root;
    }
}

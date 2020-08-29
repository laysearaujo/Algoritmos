#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node
{
    int id;
    struct node *next;
} node;

int aux_id = 0;

node *inicializa_node(int valor);
node *inserir_fila(node *head, node *tail, int id);
node *inserir_pilha(node *head, int id);
node *remove_pilha(node *pilha);
node *remove_fila(node *head, node *tail);
node *list_delete(node *head);

int main(void)
{

    node **head;
    node **tail;
    node **pilha;

    int n, i, numb, aux, j;
    char op[3];

    scanf("%i", &n);

    head = (node **)malloc(n * sizeof(node *));
    tail = (node **)malloc(n * sizeof(node *));
    pilha = (node **)malloc(n * sizeof(node *));

    for (i = 0; i < n; i++)
    {
        head[i] = (node *)malloc(sizeof(node));
        tail[i] = (node *)malloc(sizeof(node));
        pilha[i] = (node *)malloc(sizeof(node));
        tail[i] = head[i];
    }

    scanf(" %s", op);

    do
    {
        scanf("%d", &numb);
        aux_id = 0;

        if (strcmp(op, "NEW") == 0)
        {

            tail[0] = inserir_fila(head[0], tail[0], numb);
        }

        if (strcmp(op, "MOV") == 0)
        {
            head[0] = remove_fila(head[0], tail[0]);
            tail[numb] = inserir_fila(head[numb], tail[numb], aux_id);
        }

        if (strcmp(op, "DEF") == 0)
        {
            head[numb] = remove_fila(head[numb], tail[numb]);
            pilha[numb] = inserir_pilha(pilha[numb], aux_id);
        }

        if (strcmp(op, "FIX") == 0)
        {
            pilha[numb] = remove_pilha(pilha[numb]);
            tail[numb] = inserir_fila(head[numb], tail[numb], aux_id);
        }

        if (strcmp(op, "TSH") == 0)
        {
            pilha[numb] = remove_pilha(pilha[numb]);
            printf("%i BAD\n", aux_id);
        }

        if (strcmp(op, "RDY") == 0)
        {
            head[numb] = remove_fila(head[numb], tail[numb]);
            printf("%i OK\n", aux_id);
        }

        scanf(" %s", op);

    } while (strcmp(op, "END") != 0);

    return 0;
}

node *inserir_fila(node *head, node *tail, int id)
{
    node *novo = (node *)malloc(sizeof(node));
    novo->id = id;
    novo->next = tail->next;
    if (head->next == NULL)
    {
        head->next = novo;
        tail = head->next;
    }
    else
    {
        tail->next = novo;
        tail = novo;
    }
    return tail;
}

node *inserir_pilha(node *pilha, int id)
{
    node *cur = pilha;
    node *novo = (node *)malloc(sizeof(node));
    novo->id = id;
    novo->next = cur->next;
    cur->next = novo;
    return cur;
}

node *remove_pilha(node *pilha)
{

    aux_id = pilha->next->id;
    node *bye = pilha->next;
    pilha->next = bye->next;
    //aux_id = bye->id;
    if (bye != NULL)
    {
        //	free(bye);
    }
    return pilha;
}

node *remove_fila(node *head, node *tail)
{
    aux_id = head->next->id;
    node *aux = list_delete(head);
    if (head->next == NULL)
    {
        tail = head;
    }
    return head;
}

node *list_delete(node *head)
{

    node *aux = head->next;
    head->next = aux->next;
    //aux_id = aux->id;
    if (aux != NULL)
    {
        //	free(aux);
    }
    return head;
}

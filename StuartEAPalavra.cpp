#include <stdio.h>

int main()
{

    char nome, veri[100];
    int i = 0, j = 0, k = 0, aux = 0;

    while (scanf("%c", &nome) != EOF)
    {
        veri[i] = nome;
        i++;
    }
    for (j = 0; j < i; j++)
    {
        for (k = 0; k < i; k++)
        {
            if (veri[j] == veri[k])
            {
                aux++;
            }
        }
    }
    if (aux == i)
    {
        aux = 0;
    }
    if (aux > 0)
    {
        printf("NAO MANEIRA\n");
    }
    else
    {
        printf("MANEIRA\n");
    }

    return 0;
}
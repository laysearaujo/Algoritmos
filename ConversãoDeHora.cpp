#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entrada, saida;
    scanf("%d", &entrada);
    if (entrada <= 12 && entrada != 0)
    {
        saida = entrada;
    }
    else
    {
        saida = entrada + 12;
        if (saida > 24)
        {
            saida -= 24;
        }
    }
    printf("%d\n", saida);
    return 0;
}

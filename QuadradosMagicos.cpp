#include <stdio.h>

int main()
{
    int casos, tam, matriz[1000][1000] = {}, linha, coluna, k = 0, sumL[1000] = {}, sl = 0, sumC[1000] = {}, diagP = 0, diagS = 0, aux = 0, i, j, sc = 0;
    scanf("%d", &casos);
    while (casos != 0)
    {
        scanf("%d", &tam);
        //leitura
        for (linha = 0; linha < tam; linha++)
        {
            for (coluna = 0; coluna < tam; coluna++)
            {
                scanf("%d", &matriz[linha][coluna]);
            }
        }
        //somaincio
        for (linha = 0; linha < tam; linha++)
        {
            for (coluna = 0; coluna < tam; coluna++)
            {
                sl += matriz[linha][coluna]; //linha
                if (coluna == linha)
                {
                    diagP += matriz[linha][coluna]; //diagonal principal
                }
                if (linha == tam - 1 - coluna)
                {
                    diagS += matriz[linha][coluna]; //diagonal secundaria
                }
            }
            sumL[linha] = sl; //linha no vetor
            sl = 0;
        }
        for (coluna = 0; coluna < tam; coluna++)
        {
            for (linha = 0; linha < tam; linha++)
            {
                sc += matriz[linha][coluna];
            }
            sumC[coluna] = sc;
            sc = 0;
        }
        //somafim
        //printf("%d", sumC[4]);
        if (diagS != diagP)
        {
            aux++;
        }
        for (i = 0; i < tam; i++)
        {
            for (j = 0; j < tam; j++)
            {
                if (sumL[i] != sumC[j])
                {
                    aux++;
                }
            }
        }
        //printf("%d", aux);
        if (aux > 0)
        {
            printf("matrix #%d is not magic\n", k);
        }
        else
        {
            printf("matrix #%d is magic\n", k);
        }
        diagS = 0;
        diagP = 0;
        aux = 0;
        k++;
        casos--;
    }
    return 0;
}
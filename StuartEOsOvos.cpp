#include <stdio.h>

int main()
{
    int N = 0, K = 0, ovos = 0, casca = 0, i = 0;
    scanf("%d %d", &N, &K);
    ovos = N;
    while (N != 0 && casca < K)
    {
        N--;
        casca++;
        if (casca == K)
        {
            casca = 0;
            i++;
            N++;
        }
    }
    printf("%d\n", i + ovos);
    return 0;
}

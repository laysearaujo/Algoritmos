#include <stdio.h>

int main()
{
    int T;
    scanf("%d", &T);
    if (T < -20)
    {
        printf("MUITO FRIO\n");
    }
    else if (T < -10)
    {
        printf("BASTANTE FRIO\n");
    }
    else if (T < 10)
    {
        printf("FRIO\n");
    }
    else if (T < 20)
    {
        printf("MORNO\n");
    }
    else
    {
        printf("DESCONHECIDA\n");
    }
    return 0;
}
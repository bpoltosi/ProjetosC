#include <stdio.h>

int main()
{

    int vetor[4] = {10, 20, 30, 40};
    int *p = vetor;

    printf("%d", *p);
    printf("%d", *(p + 3));

    return 0;
}

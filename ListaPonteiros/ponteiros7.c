/*
ler Vetor[n] e inverter usando dois ponteiros
um no primeiro, outro no ultimo, trocando de valores
ate se encontrarem no meio
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int n;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &n);

    int vetor[n];

    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        vetor[i] = (rand() % 100);
    }

    printf("\nVetor Original:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    int *inicio = vetor;
    int *fim = vetor + n - 1;
    int aux;

    while (inicio < fim)
    {
        aux = *inicio;
        *inicio = *fim;
        *fim = aux;

        inicio++;
        fim--;
    }

    printf("\nVetor invertido:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    return 0;
}
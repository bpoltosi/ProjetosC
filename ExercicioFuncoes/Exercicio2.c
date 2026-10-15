/* Escreva um programa em C que tenha as funções:
1) void ler_vetor(int v[], int n) — lê os elementos;
2) void imprimir_vetor(int v[], int n) — imprime os elementos;
3) int maior_elemento(int v[], int n) — retorna o maior valor.
Na main, use as três funções para ler um vetor de N inteiros, imprimi-lo e mostrar o maior elemento. */

#include <stdio.h>

void ler_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &v[i]); // preenche o vetor da main
    }
}

void imprimir_vetor(int v[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}

int maior_elemento(int v[], int n)
{
    int maiorValor = v[0];

    for (int i = 1; i < n; i++)
    {
        if (maiorValor < v[i])
        {
            maiorValor = v[i];
        }
    }
    return maiorValor;
}

int main(void)
{
    int numero = 5;
    int vetor[numero];

    // Recebe os valores do Vetor
    printf("Lendo vetor!\n");
    ler_vetor(vetor, numero);

    // Imprime o Vetor
    printf("Imprimindo vetor!\n");
    imprimir_vetor(vetor, numero);

    // Procura e Imprime o Maior Elemento
    int maiorElemento = maior_elemento(vetor, numero);
    printf("\nMaior elemento: %d\n", maiorElemento);

    return 0;
}
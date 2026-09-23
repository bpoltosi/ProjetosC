/* Faça um programa que pegue N números inteiros e armazene-os em um vetor.
Ao final, o programa deverá:
a) Exibir todos os elementos do vetor;
b) Calcular e exibir a soma dos elementos;
c) Calcular e exibir a média dos valores armazenados;
d) Identificar e exibir o maior valor e o menor valor do vetor;
e) Informar quantos e quais valores são pares e quantos são ímpares;
f) Exibir todos os valores que são maiores que a média calculada.
Observação: não é permitido ordenar o vetor para realizar as operações. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    srand(time(NULL));

    int quantosNumeros = rand() % 20 + 1;
    int vetorNumeros[quantosNumeros];
    int valoresPares[quantosNumeros];
    int valoresImpares[quantosNumeros];
    int valoresMaioresMedia[quantosNumeros];
    int somaElementos = 0;
    int quantosPares = 0;
    int quantosImpares = 0;
    int quantosMaioresMedia = 0;

    for (int i = 0; i < quantosNumeros; i++)
    {
        vetorNumeros[i] = rand() % 100;
    }

    int *p = vetorNumeros;
    int maiorValor = *p;
    int menorValor = *p;
    int *ponteiroPares = valoresPares;
    int *ponteiroImpares = valoresImpares;
    int *ponteiroMaioresMedia = valoresMaioresMedia;

    printf("Numeros armazenados: ");

    for (int i = 0; i < quantosNumeros; i++)
    {
        printf("%d ", *p);
        somaElementos += *p;

        if (*p > maiorValor)
        {
            maiorValor = *p;
        }
        if (*p < menorValor)
        {
            menorValor = *p;
        }
        if (*p % 2 == 0)
        {
            *ponteiroPares = *p;
            ponteiroPares++;
            quantosPares++;
        }
        else
        {
            *ponteiroImpares = *p;
            ponteiroImpares++;
            quantosImpares++;
        }
        p++;
    }

    float mediaValores = (float)somaElementos / quantosNumeros;
    p = vetorNumeros;

    for (int i = 0; i < quantosNumeros; i++)
    {
        if (*p > mediaValores)
        {
            *ponteiroMaioresMedia = *p;
            ponteiroMaioresMedia++;
            quantosMaioresMedia++;
        }
        p++;
    }

    printf("\n\nSoma dos elementos: %d", somaElementos);
    printf("\nMedia dos valores: %.2f", mediaValores);
    printf("\nMaior valor: %d", maiorValor);
    printf("\nMenor valor: %d", menorValor);

    printf("\n\nQuantidade de pares: %d", quantosPares);
    printf("\nValores pares: ");

    for (int i = 0; i < quantosPares; i++)
    {
        printf("%d ", valoresPares[i]);
    }
    printf("\n\nQuantidade de impares: %d", quantosImpares);
    printf("\nValores impares: ");
    for (int i = 0; i < quantosImpares; i++)
    {
        printf("%d ", valoresImpares[i]);
    }
    printf("\n\nValores maiores que a media: ");
    for (int i = 0; i < quantosMaioresMedia; i++)
    {
        printf("%d ", valoresMaioresMedia[i]);
    }

    return 0;
}
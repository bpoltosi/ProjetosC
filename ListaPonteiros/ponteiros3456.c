/*  3: Escreva um programa que leia N números inteiros e os armazene em um vetor,
    usando um ponteiro para acessar cada posição durante a leitura.
    4: Escreva um programa que leia um vetor de N números inteiros e calcule a
    soma e a média dos elementos, percorrendo o vetor apenas com um ponteiro.
    5: Escreva um programa que leia um vetor de N números inteiros
    e encontre o maior e o menor valor, acessando os elementos apenas por meio de um ponteiro.
    6: Escreva um programa que leia um vetor de N números inteiros e um valor a ser procurado.
    Usando um ponteiro, percorra o vetor e informe em que posição o valor foi encontrado (ou que não foi encontrado).
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int n;

    // Recebe o Tamanho 'n' do Vetor[n]
    printf("Informe o tamanho do Vetor: ");
    scanf("%d", &n);

    int vetor[n];
    int *p = vetor;
    int somaElementos = 0, valorProcurado;

    // Gera um Vetor[n]
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        *(p + i) = rand() % 100;
    }

    int maiorElemento = (*p);
    int menorElemento = (*p);
    float mediaElementos;
    int *pMenor = p;
    int *pMaior = p;
    int encontrado = 0;

    // Imprime Vetor[n]
    printf("Valores do Vetor: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", *(p + i));
    }

    //  Recebe Valor Procurado
    printf("\nQual valor sera procurado? ");
    scanf("%d", &valorProcurado);

    //  Calcula Maior/Menor/somaElementos/EncontraElemento
    for (int i = 0; i < n; i++)
    {
        int valorAtual = *(p + i);
        somaElementos += valorAtual; // soma

        if (valorAtual > maiorElemento)
        { // maior
            maiorElemento = valorAtual;
            pMaior = (p + i);
        }
        if (valorAtual < menorElemento)
        { // menor
            menorElemento = valorAtual;
            pMenor = (p + i);
        }
        if (valorAtual == valorProcurado)
        {
            encontrado = 1;
            printf("\nValor encontrado! Posição no Vetor: [%d]", i + 1);
        }
    }

    //  Media do Vetor[n]
    mediaElementos = (float)somaElementos / n;

    // Imprime Resultados
    if (encontrado == 0)
    {
        printf("\nValor não encontrado no Vetor[n]");
    }
    printf("\nValor da Soma dos Elementos: %d", somaElementos);
    printf("\nValor do Maior Elemento: %d", maiorElemento);
    printf("\nValor do Menor Elemento: %d", menorElemento);
    printf("\nValor da Media dos Elementos: %.2f", mediaElementos);
    printf("\nValor do Endereço do Maior Elemento: %p", pMaior);
    printf("\nValor do Endereço do Menor Elemento: %p", pMenor);

    return 0;
}

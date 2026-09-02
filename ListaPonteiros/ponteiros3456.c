/*  3: Escreva um programa que leia N números inteiros e os armazene em um vetor,
    usando um ponteiro para acessar cada posição durante a leitura.
    4: Escreva um programa que leia um vetor de N números inteiros e calcule a
    soma e a média dos elementos, percorrendo o vetor apenas com um ponteiro.
    5: Escreva um programa que leia um vetor de N números inteiros
    e encontre o maior e o menor valor, acessando os elementos apenas por meio de um ponteiro.
    6: Escreva um programa que leia um vetor de N números inteiros e um valor a ser procurado.
    Usando um ponteiro, percorra o vetor e informe em que posição o valor foi encontrado (ou que não foi encontrado).

    (em alguns exercicios eu dei uma complicada na hora do codigo)
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

    // Gera um Vetor[n] -> Enunciado 3
    srand(time(NULL));
    for (int i = 0; i < n; i++)
    {
        *(p + i) = rand() % 100;    // !
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

    // Recebe Valor Procurado -> Enunciado 6
    printf("\nQual valor sera procurado? ");
    scanf("%d", &valorProcurado);

    // Calcula Maior/Menor/somaElementos/EncontraElemento -> Enunciado 4/5
    for (int i = 0; i < n; i++)
    {
        int valorAtual = *(p + i);
        somaElementos += valorAtual; // soma

        if (valorAtual > maiorElemento)
        {
            maiorElemento = valorAtual; // maior
            pMaior = (p + i);
        }
        if (valorAtual < menorElemento)
        {
            menorElemento = valorAtual; // menor
            pMenor = (p + i);
        }
        if (valorAtual == valorProcurado) // -> Enunciado 6 (encontrar o valor)
        {
            encontrado = 1;
            printf("\nValor encontrado! Posição no Vetor: [%d]", i + 1);
        }
    }

    // Media do Vetor[n]
    mediaElementos = (float)somaElementos / n;

    // Imprime Resultados
    if (encontrado == 0)
    {
        printf("\nValor não encontrado no Vetor[n]"); // -> Enunciado 6, segundo caso (nao encontrar o valor)
    }
    printf("\nValor da Soma dos Elementos: %d", somaElementos);    // soma
    printf("\nValor do Maior Elemento: %d", maiorElemento);        // maior
    printf("\nValor do Menor Elemento: %d", menorElemento);        // menor
    printf("\nValor da Media dos Elementos: %.2f", mediaElementos);// media
    printf("\nValor do Endereço do Maior Elemento: %p", pMaior);   // endereço maior
    printf("\nValor do Endereço do Menor Elemento: %p", pMenor);   // endereçoi menor

    return 0;
}

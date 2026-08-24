/* Escreva um programa que leia uma matriz M x N de números reais (float) e
calcule a soma de todos os elementos e a média geral da matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int n, m;
    float somaElementos = 0;

    printf("Digite a quantidade de linhas da matriz: ");
    scanf("%d", &m);

    printf("Digite a quantidade de colunas da matriz: ");
    scanf("%d", &n);

    float matriz[m][n];
    int quantosElementos = m * n;

    srand(time(NULL));

    for (int i = 0; i < m; i++) {               // gerar a matriz
        for (int j = 0; j < n; j++) {
            matriz[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < m; i++) {               // somar os elementos
        for (int j = 0; j < n; j++) {
            somaElementos += matriz[i][j];
        }
    }

    float mediaGeral = somaElementos / quantosElementos;

    printf("\nMatriz:\n");      // imprimir a matriz

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\nSoma dos elementos: %.2f", somaElementos);        // imprimir soma dos elementos
    printf("\nQuantidade de elementos: %d", quantosElementos);  // imprimir quantos elementos tem
    printf("\nMedia geral: %.2f\n", mediaGeral);                // imprimir a media geral dos elementos

    return 0;
}
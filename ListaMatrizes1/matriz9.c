/* Escreva um programa que leia uma matriz N x M de inteiros e conte quantos
elementos são pares, quantos são ímpares, quantos são positivos e quantos são negativos.
Imprima as quatro matrizes.  */

#include <stdio.h>

int main()
{
    int n;
    int m;
    int quantosPares = 0;
    int quantosImpares = 0;
    int quantosNegativos = 0;
    int quantosPositivos = 0;

    //leitura de N
    printf("Digite o valor de N: ");
    scanf("%d", &n);

    //leitura de M
    printf("Digite o valor de M: ");
    scanf("%d", &m);

    int matriz[n][m];

    //leitura da Matriz 1
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Informe os valores da %d linha, coluna %d: ",
                   (i + 1), (j + 1));
            scanf("%d", &matriz[i][j]);
        }
    }

    //primeira verificacao (pares)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] % 2 == 0) {
                quantosPares++;
            }
        }
    }

    int matrizPares[quantosPares];
    int kPares = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] % 2 == 0) {
                matrizPares[kPares] = matriz[i][j];
                kPares++;
            }
        }
    }

    //segunda verificacao (impares)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] % 2 != 0) {
                quantosImpares++;
            }
        }
    }

    int matrizImpares[quantosImpares];
    int kImpares = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] % 2 != 0) {
                matrizImpares[kImpares] = matriz[i][j];
                kImpares++;
            }
        }
    }

    //terceira verificacao (negativos)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] < 0) {
                quantosNegativos++;
            }
        }
    }

    int matrizNegativos[quantosNegativos];
    int kNegativos = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] < 0) {
                matrizNegativos[kNegativos] = matriz[i][j];
                kNegativos++;
            }
        }
    }

    //quarta verificacao (positivos)
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] > 0) {
                quantosPositivos++;
            }
        }
    }

    int matrizPositivos[quantosPositivos];
    int kPositivos = 0;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matriz[i][j] > 0) {
                matrizPositivos[kPositivos] = matriz[i][j];
                kPositivos++;
            }
        }
    }

    //exibicao dos valores
    printf("\nValores pares:\n");
    for(int i = 0; i < quantosPares; i++) {
        printf("%d ", matrizPares[i]);
    }

    printf("\nValores impares:\n");
    for(int i = 0; i < quantosImpares; i++) {
        printf("%d ", matrizImpares[i]);
    }

    printf("\nValores positivos:\n");
    for(int i = 0; i < quantosPositivos; i++) {
        printf("%d ", matrizPositivos[i]);
    }

    printf("\nValores negativos:\n");
    for(int i = 0; i < quantosNegativos; i++) {
        printf("%d ", matrizNegativos[i]);
    }

    printf("\n");

    return 0;
}

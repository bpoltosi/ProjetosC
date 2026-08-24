/* Escreva um programa que leia uma matriz M x N de inteiros e conte quantos
elementos são pares, quantos são ímpares, quantos são positivos e quantos são
negativos. Imprima os quatro totais.  */

#include <stdio.h>

int main(){

int n;
int m;
int quantosPares = 0;
int quantosImpares = 0;
int quantosNegativos = 0;
int quantosPositivos = 0;

    printf("Digite o valor de N: ");        //leitura de N
    scanf("%d", &n);

    printf("Digite o valor de M: ");        //leitura de M
    scanf("%d", &m);

int matriz[n][m];

    for(int i = 0; i < n; i++) {           //leitura da Matriz 1
        for(int j = 0; j < m; j++) {
            printf("Informe os valores da %d linha, coluna %d: ",
                   (i + 1), (j + 1));
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {           //primeira verificacao (pares)
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

    for(int i = 0; i < n; i++) {            //segunda verificacao (impares)
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

    for(int i = 0; i < n; i++) {            //terceira verificacao (negativos)
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

    for(int i = 0; i < n; i++) {            //quarta verificacao (positivos)
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

printf("\nValores pares:\n");               //exibicao dos valores pares
    for(int i = 0; i < quantosPares; i++) {
        printf("%d ", matrizPares[i]);
    }

printf("\nValores impares:\n");               //exibicao dos valores impares
    for(int i = 0; i < quantosImpares; i++) {
        printf("%d ", matrizImpares[i]);
    }

printf("\nValores positivos:\n");               //exibicao dos valores posotivos
    for(int i = 0; i < quantosPositivos; i++) {
        printf("%d ", matrizPositivos[i]);
    }

printf("\nValores negativos:\n");               //exibicao dos valores negativos
    for(int i = 0; i < quantosNegativos; i++) {
        printf("%d ", matrizNegativos[i]);
    }
    printf("\n");
    
return 0;
}

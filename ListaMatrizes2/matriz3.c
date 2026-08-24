/*  Faça um algoritmo que receba os valores para uma matriz 2x3, gere e
imprima uma matriz transposta. A matriz transposta é gerada trocando a linha pela
coluna (matriz[3][2] vira matriz[2][3]).  */

#include <stdio.h>

int main(void){

    int matriz[2][3];
    int matrizTransposta[3][2];

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            printf("Informe o valor correspondente a linha [%d] e coluna [%d]: ", i+1, j+1);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 3; j++){
            matrizTransposta[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz Transposta: \n");      // printar
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 2; j++){
            printf("%d, ", matrizTransposta[i][j]);
        }
        printf("\n");
    }

return 0;
}
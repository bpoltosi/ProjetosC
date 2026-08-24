/* Faça um algoritmo para ler duas matrizes reais A e B de ordem 5, e criar uma
matriz C de modo que:
c[i][j] = 1, se a[i][j] da matriz A existe em algum lugar na matriz B;
c[i][j] = 0, se a[i][j] da matriz A não existir em B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void){

    float matrizA[5][5];
    int matrizB[5][5];
    int matrizC[5][5];

    srand(time(NULL));      // gerar as 2 matrizes
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            matrizA[i][j] = rand() % 100;       // matrizA
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            matrizB[i][j] = rand() % 100;       // matrizB
        }
    }

/*    for (int i = 0; i < 5; i++)               // receber valores matrizA
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Informe o valor correspondente a linha [%d] e coluna [%d]: ", i+1, j+1);
            scanf("%f", &matrizA[i][j]);
        }
    }

    for (int i = 0; i < 5; i++)                 // receber valores matrizB
    {
        for (int j = 0; j < 5; j++)
        {
            printf("Informe o valor correspondente a linha [%d] e coluna [%d]: ", i+1, j+1);
            scanf("%d", &matrizB[i][j]);
        }
    }
*/

    
    

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matrizC[i][j] = 0;                    // c[i][j] = 0, se a[i][j] da matriz A não existir em B.

            for (int k = 0; k < 5; k++)
            {
                for (int l = 0; l < 5; l++)
                {
                    if(matrizA[i][j] == matrizB[k][l])
                    {
                        matrizC[i][j] = 1;      // c[i][j] = 1, se a[i][j] da matriz A existe em algum lugar na matriz B;
                    }
                }
            }
        }
    }

    printf("\nMatriz C: \n");       // printar
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d, ", matrizC[i][j]);
        }
        printf("\n");
    }
    return 0;
}
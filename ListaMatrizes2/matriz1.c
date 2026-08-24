/* Ler uma matriz A de ordem 5 e construir uma matriz B de mesma dimensão
cada elemento de B deve ser o dobro de cada elemento correspondente da matriz A
valores da diagonal principal de A são x3. 
Apresentar a matriz B. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int matrizA [5][5] = {0};
    int matrizB [5][5] = {0};

    srand(time(NULL));
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            matrizA[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i == j){
                matrizB[i][j] = (matrizA[i][j] * 3);        
            } else {
                matrizB[i][j] = (matrizA[i][j] * 2);
            }
        }
    }

    
    printf("\nMatriz A: \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d, ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B: \n");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%d, ", matrizB[i][j]);
        }
        printf("\n");
    }
return 0;
}
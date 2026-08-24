/* Ler uma matriz A de ordem 5 e construir uma matriz B de mesma dimensão,
onde cada elemento de B deve ser o dobro de cada elemento correspondente da
matriz A, com exceção para os valores situados na diagonal principal os quais
devem ser o triplo de cada elemento correspondente a A. Apresentar a matriz B. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    int matrizA [5][5];
    int matrizB [5][5];

/*      
        for (int i = 0; i < 5; i++){                                            // receber matrizA
            for (int j = 0; j < 5; j++){
                printf("Informe o valor correspondente a linha [%d] e coluna [%d] da MatrizA: ", i+1, j+1);
                scanf("%f", &matrizA[i][j]);
            }
        }
*/

    srand(time(NULL));      // gerar matrizA[5][5]
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++){
            matrizA[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < 5; i++){        // percorre matriz
        for (int j = 0; j < 5; j++){
            if (i == j){
                matrizB[i][j] = (matrizA[i][j] * 3);        // valores da diagonal principal de A são o triplo.
            } else {
                matrizB[i][j] = (matrizA[i][j] * 2);        // cada elemento da matrizB deve ser o dobro de cada elemento correspondente da matrizA 
            }
        }
    }

    
    printf("\nMatriz A: \n");               // printa matrizA
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d, ", matrizA[i][j]);
        }
        printf("\n");
    }

    printf("\nMatriz B: \n");           // printa matrizB
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%d, ", matrizB[i][j]);
        }
        printf("\n");
    }
return 0;
}
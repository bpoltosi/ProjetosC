/* Ler uma matriz 4x3 com valores reais e mostrar qual é o elemento
armazenado em uma linha L e coluna C fornecidas pelo usuário. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    float matriz [4][3];
    int linha;
    int coluna;

    srand(time(NULL));
    
    for (int i = 0; i < 4; i++) {                    // gerar matriz[4][3]
        for (int j = 0; j < 3; j++){
            matriz[i][j] = rand() % 100;
        }
    }

/*    for (int i = 0; i < 4; i++){                                            // receber matriz
        for (int j = 0; j < 3; j++){
            printf("Informe o valor correspondente a linha [%d] e coluna [%d]: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }
*/


    printf("\nQual a linha do numero que voce deseja? ");                   // receber valor linha
    scanf("%d", &linha);

    while(linha > 4 || linha <= 0){                                         // validar linha
        printf("valor inválido, tente novamente");
        scanf("%d", &linha);
    }

    printf("Qual a coluna do numero que voce deseja? ");                    // receber valor coluna
    scanf("%d", &coluna);
    
    while(coluna > 3 || coluna <= 0){                                     // validar coluna
        printf("valor inválido, tente novamente");
        scanf("%d", &coluna);
    }
    printf("\nValor da Matriz[%d][%d]: %d", linha, coluna, matriz[linha-1][coluna-1]);      // printar

    return 0;
}
/* Criar uma matriz 3x4 onde cada elemento é a soma dos índices da sua
posição dentro da matriz. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    int matriz[3][4];

    srand(time(NULL)); // gerar a matriz[3][4]

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }

    for (int i = 0; i < 3; i++)
    { // percorrer matriz
        for (int j = 0; j < 4; j++)
        {
            matriz[i][j] = (i + j); // atribuir valores matriz[i][j] == i+j
        }
    }

    printf("\nMatriz: \n"); // printar
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d, ", matriz[i][j]);
        }
        printf("\n");
    }

    return 0;
}
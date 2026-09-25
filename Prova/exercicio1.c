/* Faca um programa para ler dois vetores A e B de 5 elementos cada.
Depois construa uma matriz C de 5x3, em que a primeira coluna deve ser formada pelos elementos do vetor A,
a segunda coluna formada pelos elementos do vetor B e a terceira coluna a multiplicacao dos elementos das de cada linha.
Apresentar a matriz C. Ex: 
Linha 0 : [2,3,6] */

#include <stdio.h>

int main (void)
{

    int vetorA[5];
    int vetorB[5];

    printf("Informe os 5 elementos do Vetor A: ");
    for(int i=0; i<5; i++)
    {
        scanf("\n%d", &vetorA[i]);
    }

    printf("\nInforme os 5 elementos do Vetor B: ");
    for(int i=0; i<5; i++)
    {
        scanf("\n%d", &vetorB[i]);
    }

    int vetorC[5][3];

    for(int i=0; i<5; i++)
    {
        vetorC[i][1] = vetorA[i];
        vetorC[i][2] = vetorB[i];
        vetorC[i][3] = vetorA[i] * vetorB[i];
    }

    printf("MatrizC:\n");
    for(int j =1; j<4; j++)
    {
        printf("\nLinha %d: ", j);
        for(int i=0; i<5; i++)
        {
            printf("%d;", vetorC[i][j]);
        }
    }
    return 0;
}

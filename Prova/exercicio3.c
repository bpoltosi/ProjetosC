/* Escreva um programa que leia um vetor de 10 numeros inteiros e 
encontre a janela de maior valor usando ponteiros para manipular o vetor,
sendo o  tamanho da janela de 2 elementos. Ex:
Vetor: [1,1,2,1,2,4,7,1,1,1]
Janela 1: [1,1] = 2
Janela 2: [1,2] = 3
Janela 3: [2,1] = 3
Janela 4: [1,2] = 3 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main (void)
{

    srand(time(NULL));
    int vetor[10];

    printf("Vetor Original: ");
    for (int i = 0; i < 10; i++)
    {
        vetor[i] = (rand() % 100);
        printf("%d,", vetor[i]);
    }

    int *p1 = vetor;
    int maiorSoma = 0;

    for(int i=0; i<10; i++)
    {
        if (*p1 + *(p1+1) >= maiorSoma)
        {
            maiorSoma = *p1 + *(p1+1);
        }
        p1++;
    }

    printf("\nMaior soma: %d", maiorSoma);

    return 0;
}

/* Escreva um programa em C que declare uma matriz de caracteres com 6 linhas e 10 colunas, 
leia do teclado uma frase de ate 60 caracteres, incluindo espacos usando o fgets().
Lembre de remover o caractere '\n' que o fgets deixa no final da frase. 
Apos, insira a frase na matriz caractere por caractere, linha a linha, comecando na posicao [0][0]. 
Preencha todas as posicoes que sobrarem com o caractere *. 
Se a frase digitada tiver mais de 60 caracteres, ignore o excesso e exiba a mensagem "Frase truncada!". 
Mostre a matriz na tela, uma linha por vez, com cada linha entre barras verticais (|), para que os espacos fiquem visiveis. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(void)
{

    int matriz[6][10];
    char frase[60];

    printf("Digite uma frase: ");
    fgets(frase, 60, stdin);

    int tam = (int) strlen(frase);
    if (tam > 0 && frase[tam-1] == '\n')
    {
        frase[tam-1] = '\0';
    }

    char *p = frase;

    for(int i=0; i<6; i++)
    {
        for(int j=0; j<10; j++)
        {
            matriz[i][j] = *p;
            p++;
        }
    }

    for(int i=0; i<6; i++)
    {
        printf("\n");
        for(int j=0; j<10; j++)
        {
            printf("%c, ", matriz[i][j]);
        }
    }

    return 0;
}

/*
1) Crie a biblioteca estatistica (estatistica.h e estatistica.c) com as funções media, maior e menor
2) Crie também a biblioteca arquivos, com a função ler_vetor_arquivo vista nesta aula
3) Escreva um programa que use as duas bibliotecas para ler numeros.txt e mostrar as estatísticas dos valores
4) Compile passando os três arquivos .c ao gcc
*/

#include <stdio.h>
#include <stdlib.h>
#include "estatistica.h"
#include "arquivos.h"

int main (void)
{
    float media;
    int numero, quantidade = 0,soma = 0, maior, menor;

    FILE *arquivo = fopen("numeros.txt", "r");

    if (arquivo == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    while (fscanf(arquivo, "%d", &numero) == 1)
    {
        if (quantidade == 0)
        {
            maior = numero;
            menor = numero;
        }

        soma += numero;
        quantidade++;

        if (numero > maior)
        {
            maior = numero;
        }
        if (numero < menor)
        {
            menor = numero;
        }
    }

    if (quantidade > 0)
    {
        media = (float) soma / quantidade;

        fclose(arquivo);

        printf("Quantidade de numeros: %d\n", quantidade);
        printf("Valor da soma dos numeros: %d\n", soma);
        printf("Valor da media dos numeros: %.2f\n", media);
        printf("Valor do maior numero: %d\n", maior);
        printf("Valor do menor numero: %d\n", menor);
    }
    else
    {
        printf("O arquivo esta vazio.\n");
    }

    fclose(arquivo);
}
return 0;
}

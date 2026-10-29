/* Crie, em um editor de texto, o arquivo numeros.txt com alguns números inteiros.
Depois, escreva um programa em C que:
1 Abra o arquivo para leitura, verificando se a abertura deu certo;
2 Leia todos os números com fscanf e mostre a quantidade, a soma, a média, o maior e o menor;
3 Feche o arquivo ao final. */

#include <stdio.h>
#include <stdlib.h>

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
    return 0;
}

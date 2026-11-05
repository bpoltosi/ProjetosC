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

#define MAX_NUMEROS 1000

//    Implementações

float media(int vet[], int tamanho) {
    if (tamanho <= 0) return 0.0f;
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += vet[i];
    }
    return (float)soma / tamanho;
}

int maior(int vet[], int tamanho) {
    if (tamanho <= 0) return 0;
    int m = vet[0];
    for (int i = 1; i < tamanho; i++) {
        if (vet[i] > m) m = vet[i];
    }
    return m;
}

int menor(int vet[], int tamanho) {
    if (tamanho <= 0) return 0;
    int m = vet[0];
    for (int i = 1; i < tamanho; i++) {
        if (vet[i] < m) m = vet[i];
    }
    return m;
}

int ler_vetor_arquivo(char *nome_arquivo, int vet[], int tamanho_max) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        return -1;
    }

    int quantidade = 0;
    while (quantidade < tamanho_max && fscanf(arquivo, "%d", &vet[quantidade]) == 1) {
        quantidade++;
    }

    fclose(arquivo);
    return quantidade;
}

int main (void)
{
    int vetor[MAX_NUMEROS];
    int quantidade;

    quantidade = ler_vetor_arquivo("numeros.txt", vetor, MAX_NUMEROS);

    if (quantidade < 0) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    if (quantidade == 0) {
        printf("O arquivo esta vazio.\n");
        return 0;
    }

    int soma = 0;
    for (int i = 0; i < quantidade; i++) {
        soma += vetor[i];
    }

    printf("Quantidade de numeros: %d\n", quantidade);
    printf("Valor da soma dos numeros: %d\n", soma);
    printf("Valor da media dos numeros: %.2f\n", media(vetor, quantidade));
    printf("Valor do maior numero: %d\n", maior(vetor, quantidade));
    printf("Valor do menor numero: %d\n", menor(vetor, quantidade));

    return 0;
}

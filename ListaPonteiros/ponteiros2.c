/*  Escreva um programa que leia dois números inteiros em variáveis "a" e "b" e
    troque os valores entre elas usando ponteiros.  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{

    int a;
    int b;

    printf("Informe o valor de A: ");
    scanf("%d", &a);
    printf("Informe o valor de B: ");
    scanf("%d", &b);

    int *pa = &a;
    int *pb = &b;
    int aux;

    *pa = aux;
    *pa = *pb;
    *pb = aux;

    // Imprime A e B
    printf("\nValor de A: %d", a);
    printf("\nValor de B: %d", b);

    return 0;
}

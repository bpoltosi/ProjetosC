/*  1: Escreva um programa que declare uma variável inteira e um ponteiro para ela.
    Usando o ponteiro, imprima o valor da variável e o seu endereço (com %p). */

#include <stdio.h>

int main()
{
    int numero = 42; 
    int *ponteiro = &numero; 

    printf("Valor da variavel: %d\n", *ponteiro);
    printf("Endereco da variavel: %p\n", ponteiro);

    return 0;
}

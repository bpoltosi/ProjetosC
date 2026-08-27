/*  Escreva um programa completo em C que:
Leia um vetor de 10 números inteiros;
Usando apenas um ponteiro (sem colchetes),
encontre e imprima o maior e o menor valor do vetor;
Calcule também a soma de todos os elementos, sempre pelo ponteiro  */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    
int vetor[10];
int *p = vetor;
int somaElementos = 0;

/*//  Le um Vetor[10]
for (int i = 0; i < 10; i++) {
    printf("Informe o valor da posição Vetor[%d]: ",i);
    scanf("%d", (p+i));
}*/

// Gera um Vetor[10]
srand(time(NULL));
for (int i = 0; i < 10; i++) {
        *(p+i) = rand() % 100;
}

//  Inicializa elementos dependentes
int menorElemento = (*p);
int maiorElemento = (*p);

// Imprime Vetor[10]
printf("Valores do Vetor: ");
for (int i = 0; i < 10; i++) {
    printf("%d, ", *(p+i));
}

//  Soma Elementos & Calcula Maior/Menor elemento
for (int i = 0; i < 10; i++) {
    int valorAtual = *(p + i);
    somaElementos += valorAtual;    //soma

    if (valorAtual > maiorElemento) {   //maior
        maiorElemento = valorAtual;
    }
    if (valorAtual < menorElemento) {   //menor
        menorElemento = valorAtual;
    }
}
        
// Imprime Resultados
printf("\nValor da Soma dos Elementos: %d", somaElementos);
printf("\nValor do Maior Elemento: %d", maiorElemento);
printf("\nValor do Menor Elemento: %d", menorElemento);

return 0;
}

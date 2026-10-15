#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int numero[15];
} Cartela;

typedef struct {
    char nome[50];
    char codinome[50];
    Cartela cartela;
} Jogador;

int sortearNumero (int numerosSorteados[], int qtsNumerosSorteados){   // ja valida o numero sorteado
    int n = rand() % 60 + 1;
    for (int i=0; i<qtsNumerosSorteados; i++){
        while (n == numerosSorteados[i]){
            n = (rand()%60 + 1);
        }
    }
    return n;
}

void armazenaNumeroSorteado (int numerosSorteados[], int *qtsNumerosSorteados){

    int n = sortearNumero(numerosSorteados, *qtsNumerosSorteados);

    numerosSorteados[*qtsNumerosSorteados] = n;
    (*qtsNumerosSorteados)++;
}

int main(void) {
    int qtsNumerosSorteados = 0;
    int numerosSorteados[60];

    srand(time(NULL));

    for (int z = 1; z <= 60; z++) {
        armazenaNumeroSorteado(numerosSorteados,&qtsNumerosSorteados);
        printf("Numero sorteado: %d\n", numerosSorteados[z - 1]);
        printf("Na posicao: %d\n", z);
    }
    return 0;
}
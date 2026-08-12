/* Escreva um algoritmo que declare um vetor de inteiros com capacidade
para 8 elementos. O programa deve ler os 8 números do teclado via laço de
repetição e, em seguida, utilizar um segundo laço para exibir todos os elementos do
vetor na ordem inversa à que foram digitados */

#include <stdio.h>

int main(void) {

	int valores [8];
	int valoresInvertidos [8];

	for (int i = 0; i < 8; i++) {
		printf("Informe os valores inteiros: ");
		scanf("%d", &valores[i]);
	}

	for(int i = 0; i < 8; i++) {
		valoresInvertidos[i] = valores[7-i];
	}

	printf("Sequencia inversa dos numeros informados: %d", valoresInvertidos);
	return 0;
}

/* ainda esta errado! */

/* algoritmo que le um vetor de 10 números inteiros, gerando um segundo vetor contendo apenas os números digitados que
sejam maiores que a média de todos os elementos inseridos. Exibindo o vetor final e o número de elementos válidos copiados para ele. 
DIFICIL! */

#include <stdio.h>

int main(void) {

	int valores[10];
	int somaTotal = 0;
	int quantosAceitos = 0;
	int percorrerVetor = 0;

	for (int i = 0; i < 10; i++) {
		printf("Informe os valores inteiros: ");
		scanf("%d", &valores[i]);
		somaTotal = valores[i] + somaTotal;
	}

	float media = somaTotal / 10.0;

	for (int i = 0; i < 10; i++) {

		if (valores[i] > media) {
			quantosAceitos++;
		}
	}
	int valoresAceitos[quantosAceitos];

	for (int i = 0; i < 10; i++) {

		if (valores[i] > media) {
			valoresAceitos[percorrerVetor] = valores[i];
			percorrerVetor++;
		}
	}

	printf("Quais valores foram maiores que a media: ");

	for (int i = 0; i < quantosAceitos; i++) {
		printf("%d, ", valoresAceitos[i]);
	}

	printf("\nQuantidade de elementos aceitos: %d", quantosAceitos);

	return 0;
}

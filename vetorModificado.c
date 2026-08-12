/* Crie um código em C que declare e leia um vetor de 12 posições de
inteiros. Em seguida, percorra o vetor substituindo todos os números negativos
encontrados pelo valor 0, e todos os números ímpares positivos pelo valor 1.
Imprima o vetor resultante modificado.*/

#include <stdio.h>

int main(void) {

	int vetor[12];

	for (int i = 0; i < 12; i++) {
		printf("Digite um valor: ");
		scanf("%d", &vetor[i]);
	}

	for (int i = 0; i < 12; i++) {

		if (vetor[i] < 0);
		{
			vetor[i] = 0;
		}

		if(vetor[i] % 2 != 0 && vetor[i] > 0);
		{
			vetor[i] = 1;
		}
	}

    
	printf("Resultado do vetor modificado: ");

	for (int i = 0; i < 12; i++) {
		printf("%d", vetor[i]);
	}

	return 0;
}

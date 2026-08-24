/* tabuada até o 10, com validação de entrada (n<0) */

#include <stdio.h>

int main(void) {
	int numero;
	int multiplicacao;

	printf("Digite um numero inteiro positivo: ");
	scanf("%d", &numero);
	if (numero < 0) {
		printf("Digite um numero válido!");
	}   else {
		for (int n = 1; n < 11; n++) {
			multiplicacao = numero * n;
			printf("%d * %d = %d \n", numero, n, multiplicacao);
		}
	}
	return 0;
}

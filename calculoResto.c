/* codigo que exibe quantos/quais numeros dão resto cinco quando divididos por 11 */

#include <stdio.h>

int main (void) {

	printf("Números divisíveis por 11 que dão resto cinco \n");

	for (int i = 100; i <= 200; i++) {
		if (i%11 == 5) {
			int valorAceito = i;
			int quantosNumerosAceitos ++;
			printf("Foram descobertos %d números que atendem os requisitos!", quantosNumerosAceitos);
			printf("%d , ", valorAceito);
		}
	}
	return 0;
}

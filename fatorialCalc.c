\* calculo de valor do fatorial de 'n' *\

#include <stdio.h>

int main (void) {
	int valorN;
	int valorTotalFatorial = 1;

	printf (" Digite o valor de 'n' : ");
	scanf ("%d", &valorN );

	if (valorN > 1) {
		do {
			valorTotalFatorial *= valorN;
			valorN--;
		}
		while (valorN != 1);
	}
	printf (" Valor do fatorial de 'n' : %d", valorTotalFatorial);
	return 0;
}

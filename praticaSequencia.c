/* leitura, soma dos positivos e contagem de negativos */

#include <stdio.h>

int main (void) {
	int numero;
	int somaTodos = 0;
	int quantosNegativos = 0;

	while (numero != 0) {
        printf("Digite o numero: ");
        scanf("%d", &numero);
        
        if (numero == 0){
            break;
        }

		if (numero > 0) {
			somaTodos += numero;
		}

		if (numero < 0) {
			quantosNegativos++;
		}
	}
		printf("Soma de todos números digitados: %d \n", somaTodos);
		printf("Quantidade de números negativos digitados: %d", quantosNegativos);
		return 0;
}

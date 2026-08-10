/* script que faz a validação da entrada da Nota de avaliação */
#include <stdio.h>

int main (void) {
	float nota;

	printf("Informe a nota de avaliação: ");
	scanf("%f", &nota);

	do {
		printf("Digite um valor válido, entre 0 e 10! \n");
	    printf("Informe a nota de avaliação: ");
		scanf("%f", &nota);
	}
	while (0 > nota > 10);
  
	return 0;
}
